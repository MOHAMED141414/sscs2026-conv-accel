//=============================================================================
// conv_accel.v  -  Streaming 3x3 convolution core  (XST 14.7 compatible)
// IEEE SSCS Egypt Chapter 2026 Student Design Competition
//
// Throughput : 1 output pixel / cycle (fully pipelined, no stalls)
// Border     : VALID (no padding). out = (IMG_H-2) x (IMG_W-2)
// Arithmetic : uint8 pixel x int8 coeff -> int17 product
//              -> 3 row sums -> 22-bit accumulator -> saturate int16 -> ReLU
//
// Pipeline (3 registered stages after the window):
//   S1 : nine products
//   S2 : three row sums
//   S3 : total + saturate + optional ReLU
//
//-----------------------------------------------------------------------------
// XST 14.7 COMPATIBILITY NOTES
//
// This core was first written generically for NxN using arrays and generate
// loops. Icarus Verilog accepts that, but ISE 14.7's XST does not:
//
//   Xst:902  - array elements (prod, rsum) cannot appear in an always @(*)
//              implicit sensitivity list
//   Xst:2634 - for-loop stop conditions over arrays inside always blocks
//              are rejected even when the bound is a static parameter
//
// So the datapath below is written with FLAT VECTORS for the line buffers
// and DISCRETE REGISTERS for the window, coefficients, products and row sums.
// The arithmetic and pipeline depth are identical to the generic version;
// only the coding style changed. N is fixed at 3, which is what the
// competition requires. IMG_W and IMG_H remain parameters.
//
// Line buffers are flat shift registers so XST infers SRL32/SRL16 in LUTs
// rather than allocating BRAM. This is deliberate: the competition FoM
// charges 100 penalty units per BRAM.
//=============================================================================

`timescale 1ns / 1ps
`default_nettype none

module conv_accel #(
    parameter integer IMG_W   = 32,   // input width  (line buffer depth)
    parameter integer IMG_H   = 32,   // input height
    parameter integer N       = 3,    // fixed at 3 in this implementation
    parameter integer PIX_W   = 8,    // input pixel width  (unsigned)
    parameter integer COEF_W  = 8,    // kernel coeff width (signed)
    parameter integer OUT_W   = 16,   // output width (signed, saturated)
    parameter integer PROD_W  = PIX_W + COEF_W + 1,   // 17
    parameter integer ACC_W   = PROD_W + 5,           // 22
    parameter integer COEF_AW = 4
)(
    input  wire                      clk,
    input  wire                      rst,        // synchronous, active high

    // ---- kernel coefficient load port -------------------------------------
    input  wire                      coef_we,
    input  wire [COEF_AW-1:0]        coef_addr,  // row-major: r*3 + c
    input  wire signed [COEF_W-1:0]  coef_din,

    // ---- control ----------------------------------------------------------
    input  wire                      relu_en,
    input  wire                      frame_rst,  // resets counters/valid for next kernel pass

    // ---- pixel stream in --------------------------------------------------
    input  wire                      in_valid,
    input  wire [PIX_W-1:0]          in_pixel,

    // ---- feature map out --------------------------------------------------
    output reg                       out_valid,
    output reg  signed [OUT_W-1:0]   out_pixel
);

    localparam integer LBW     = PIX_W * IMG_W;      // line buffer bit width
    localparam signed [OUT_W-1:0] SAT_MAX = 16'sh7FFF;   //  32767
    localparam signed [OUT_W-1:0] SAT_MIN = 16'sh8000;   // -32768

    //-------------------------------------------------------------------------
    // Kernel coefficients - nine discrete registers with a write decoder.
    //-------------------------------------------------------------------------
    reg signed [COEF_W-1:0] c0, c1, c2, c3, c4, c5, c6, c7, c8;

    always @(posedge clk) begin
        if (coef_we) begin
            case (coef_addr)
                4'd0: c0 <= coef_din;
                4'd1: c1 <= coef_din;
                4'd2: c2 <= coef_din;
                4'd3: c3 <= coef_din;
                4'd4: c4 <= coef_din;
                4'd5: c5 <= coef_din;
                4'd6: c6 <= coef_din;
                4'd7: c7 <= coef_din;
                4'd8: c8 <= coef_din;
                default: ;
            endcase
        end
    end

    //-------------------------------------------------------------------------
    // Line buffers - two flat shift registers, IMG_W pixels deep.
    // lb0_out is the pixel from 1 row back, lb1_out from 2 rows back.
    //-------------------------------------------------------------------------
    reg [LBW-1:0] lb0, lb1;

    wire [PIX_W-1:0] lb0_out = lb0[LBW-1 -: PIX_W];
    wire [PIX_W-1:0] lb1_out = lb1[LBW-1 -: PIX_W];

    always @(posedge clk) begin
        if (in_valid) begin
            lb0 <= {lb0[LBW-PIX_W-1:0], in_pixel};
            lb1 <= {lb1[LBW-PIX_W-1:0], lb0_out};
        end
    end

    //-------------------------------------------------------------------------
    // 3x3 window. Row 0 is the oldest (2 rows back), row 2 the newest.
    //-------------------------------------------------------------------------
    reg [PIX_W-1:0] w00, w01, w02;
    reg [PIX_W-1:0] w10, w11, w12;
    reg [PIX_W-1:0] w20, w21, w22;

    always @(posedge clk) begin
        if (in_valid) begin
            w00 <= w01;  w01 <= w02;  w02 <= lb1_out;   // 2 rows back
            w10 <= w11;  w11 <= w12;  w12 <= lb0_out;   // 1 row back
            w20 <= w21;  w21 <= w22;  w22 <= in_pixel;  // current row
        end
    end

    //-------------------------------------------------------------------------
    // Position counters -> window validity
    //-------------------------------------------------------------------------
    reg [15:0] col_cnt;
    reg [15:0] row_cnt;
    wire win_valid = in_valid && (row_cnt >= 2) && (col_cnt >= 2);

    always @(posedge clk) begin
        if (rst || frame_rst) begin
            col_cnt <= 16'd0;
            row_cnt <= 16'd0;
        end else if (in_valid) begin
            if (col_cnt == IMG_W-1) begin
                col_cnt <= 16'd0;
                row_cnt <= row_cnt + 16'd1;
            end else begin
                col_cnt <= col_cnt + 16'd1;
            end
        end
    end

    // Alignment: `win` and `win_valid` update on the same edge, so at the edge
    // that admits pixel (r,c) the product stage still reads the window ending
    // at (r,c-1). win_valid is therefore delayed one cycle to line up with the
    // data the multipliers actually see.
    reg win_valid_q, v1, v2;

    //-------------------------------------------------------------------------
    // S1 : nine products.  uint8 zero-extended to signed, times signed coeff.
    //-------------------------------------------------------------------------
    wire signed [PIX_W:0] x00 = $signed({1'b0, w00});
    wire signed [PIX_W:0] x01 = $signed({1'b0, w01});
    wire signed [PIX_W:0] x02 = $signed({1'b0, w02});
    wire signed [PIX_W:0] x10 = $signed({1'b0, w10});
    wire signed [PIX_W:0] x11 = $signed({1'b0, w11});
    wire signed [PIX_W:0] x12 = $signed({1'b0, w12});
    wire signed [PIX_W:0] x20 = $signed({1'b0, w20});
    wire signed [PIX_W:0] x21 = $signed({1'b0, w21});
    wire signed [PIX_W:0] x22 = $signed({1'b0, w22});

    reg signed [PROD_W-1:0] p0, p1, p2, p3, p4, p5, p6, p7, p8;

    always @(posedge clk) begin
        p0 <= x00 * c0;
        p1 <= x01 * c1;
        p2 <= x02 * c2;
        p3 <= x10 * c3;
        p4 <= x11 * c4;
        p5 <= x12 * c5;
        p6 <= x20 * c6;
        p7 <= x21 * c7;
        p8 <= x22 * c8;
    end

    always @(posedge clk) win_valid_q <= (rst || frame_rst) ? 1'b0 : win_valid;
    always @(posedge clk) v1          <= (rst || frame_rst) ? 1'b0 : win_valid_q;

    //-------------------------------------------------------------------------
    // S2 : three row sums (3-term adders keep combinational depth short)
    //-------------------------------------------------------------------------
    reg signed [ACC_W-1:0] rs0, rs1, rs2;

    always @(posedge clk) begin
        rs0 <= p0 + p1 + p2;
        rs1 <= p3 + p4 + p5;
        rs2 <= p6 + p7 + p8;
    end

    always @(posedge clk) v2 <= rst ? 1'b0 : v1;

    //-------------------------------------------------------------------------
    // S3 : total, saturate to int16, optional ReLU
    //-------------------------------------------------------------------------
    wire signed [ACC_W-1:0] total = rs0 + rs1 + rs2;

    wire signed [OUT_W-1:0] sat =
        (total > $signed({{(ACC_W-OUT_W){1'b0}}, SAT_MAX})) ? SAT_MAX :
        (total < $signed({{(ACC_W-OUT_W){1'b1}}, SAT_MIN})) ? SAT_MIN :
                                                             total[OUT_W-1:0];

    wire signed [OUT_W-1:0] relu = (relu_en && sat[OUT_W-1]) ? {OUT_W{1'b0}} : sat;

    always @(posedge clk) begin
        if (rst || frame_rst) begin
            out_valid <= 1'b0;
            out_pixel <= {OUT_W{1'b0}};
        end else begin
            out_valid <= v2;
            out_pixel <= relu;
        end
    end

endmodule

`default_nettype wire
