//=============================================================================
// conv_accel_same.v  -  3x3 convolution core, TRUE zero-gap SAME padding
//
// Unlike conv_accel.v (VALID border, used by the base design), this core:
//   - Accepts the image at its NATIVE size (IMG_W x IMG_H) -- no literal
//     padding pixels are fed in. TOP padding comes for free from the line
//     buffers' zero-reset state (see reasoning below). LEFT padding is
//     applied by masking the window's two oldest columns to zero whenever
//     fewer than 2/1 real pixels of the current row have been seen.
//   - win_valid = in_valid (pipeline-delayed). EVERY real pixel produces
//     exactly one output -- no row/col threshold, no injected padding
//     cycles, hence NO row-boundary gap. Output count = IMG_W * IMG_H.
//
// WHY TOP PADDING IS AUTOMATIC:
//   lb0/lb1 are IMG_W-deep shift registers, reset to all-zero. lb0_out is
//   "1 row back, same column"; it only starts returning real data after
//   IMG_W valid pushes (i.e. once row 1 begins) -- before that it outputs
//   the reset zero, exactly matching "row -1 doesn't exist". lb1_out (2
//   rows back) similarly stays zero through row 0 AND row 1, since it is
//   fed from lb0_out, which was zero throughout row 0. This requires lb0/
//   lb1 to be explicitly reset to zero on rst/frame_rst (unlike the VALID
//   core, which doesn't need this since row_cnt>=2 gating already discards
//   any output computed from stale/undefined line-buffer content).
//
// WHY LEFT PADDING NEEDS MASKING:
//   The window registers (w00..w22) are a pure shift chain with no reset
//   between rows, so at a new row's first 1-2 pixels they still hold the
//   PREVIOUS row's trailing pixels -- wraparound contamination, not zero.
//   Masking w_0 (oldest column) when col_cnt<3, and w_1 (middle column)
//   when col_cnt<2, substitutes zero for those positions, matching the
//   golden SAME model (pad=N-1=2, left/top only).
//=============================================================================
`timescale 1ns / 1ps
`default_nettype none

module conv_accel_same #(
    parameter integer IMG_W = 32,
    parameter integer IMG_H = 32,
    parameter integer N     = 3
)(
    input  wire                      clk,
    input  wire                      rst,

    // ---- coefficient load ---------------------------------------------------
    input  wire                      coef_we,
    input  wire [3:0]                coef_addr,
    input  wire signed [7:0]         coef_din,

    // ---- control --------------------------------------------------------
    input  wire                      relu_en,
    input  wire                      frame_rst,

    // ---- pixel stream -----------------------------------------------------
    input  wire                      in_valid,
    input  wire [7:0]                in_pixel,

    // ---- result stream ------------------------------------------------------
    output reg                       out_valid,
    output reg  signed [15:0]        out_pixel
);
    localparam integer PIX_W  = 8;
    localparam integer COEF_W = 8;
    localparam integer PROD_W = 17;
    localparam integer ACC_W  = 22;
    localparam integer OUT_W  = 16;
    localparam integer LBW    = IMG_W * PIX_W;   // 256 for IMG_W=32

    localparam signed [OUT_W-1:0] SAT_MAX = 16'sb0111111111111111;
    localparam signed [OUT_W-1:0] SAT_MIN = 16'sb1000000000000000;

    //-------------------------------------------------------------------------
    // Coefficient register file
    //-------------------------------------------------------------------------
    reg signed [COEF_W-1:0] c0,c1,c2,c3,c4,c5,c6,c7,c8;

    always @(posedge clk) begin
        if (coef_we) begin
            case (coef_addr)
                4'd0: c0 <= coef_din;  4'd1: c1 <= coef_din;  4'd2: c2 <= coef_din;
                4'd3: c3 <= coef_din;  4'd4: c4 <= coef_din;  4'd5: c5 <= coef_din;
                4'd6: c6 <= coef_din;  4'd7: c7 <= coef_din;  4'd8: c8 <= coef_din;
                default: ;
            endcase
        end
    end

    //-------------------------------------------------------------------------
    // Line buffers -- MUST reset to zero (see header comment)
    //-------------------------------------------------------------------------
    reg [LBW-1:0] lb0, lb1;
    wire [PIX_W-1:0] lb0_out = lb0[LBW-1 -: PIX_W];
    wire [PIX_W-1:0] lb1_out = lb1[LBW-1 -: PIX_W];

    always @(posedge clk) begin
        if (rst || frame_rst) begin
            lb0 <= {LBW{1'b0}};
            lb1 <= {LBW{1'b0}};
        end else if (in_valid) begin
            lb0 <= {lb0[LBW-PIX_W-1:0], in_pixel};
            lb1 <= {lb1[LBW-PIX_W-1:0], lb0_out};
        end
    end

    //-------------------------------------------------------------------------
    // 3x3 window (pure shift chain, no per-row reset -- masking handles it)
    //-------------------------------------------------------------------------
    reg [PIX_W-1:0] w00, w01, w02;
    reg [PIX_W-1:0] w10, w11, w12;
    reg [PIX_W-1:0] w20, w21, w22;

    always @(posedge clk) begin
        if (in_valid) begin
            w00 <= w01;  w01 <= w02;  w02 <= lb1_out;
            w10 <= w11;  w11 <= w12;  w12 <= lb0_out;
            w20 <= w21;  w21 <= w22;  w22 <= in_pixel;
        end
    end

    //-------------------------------------------------------------------------
    // Position counters (needed for masking + row-wrap tracking)
    //-------------------------------------------------------------------------
    reg [15:0] col_cnt;   // pixels fed so far in current row, post-edge (1..IMG_W then wraps 0)
    reg [15:0] row_cnt;

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

    // Every real pixel produces exactly one output -- pipeline-delayed only.
    wire win_valid = in_valid;
    reg win_valid_q, v1, v2;

    //-------------------------------------------------------------------------
    // Column masking: substitute zero for window columns that would
    // otherwise carry wraparound contamination from the previous row.
    //
    // col_cnt WRAPS to 0 right after the last pixel of a row, so it can't
    // directly distinguish "just wrapped, deep in a full row" from "just
    // started a new row" -- both read as col_cnt==0 at different points.
    // rundist instead counts consecutive same-row pushes, saturating at 3,
    // reset to 1 specifically when THIS push is a row's first pixel
    // (detected from the PRE-update col_cnt, same signal win_valid uses).
    //   w_0 (oldest column: w00,w10,w20) valid only once rundist>=3
    //   w_1 (middle column: w01,w11,w21) valid only once rundist>=2
    //   w_2 (newest column: w02,w12,w22) always valid (current pixel)
    //-------------------------------------------------------------------------
    reg [1:0] rundist;
    always @(posedge clk) begin
        if (rst || frame_rst) begin
            rundist <= 2'd0;
        end else if (in_valid) begin
            if (col_cnt == 16'd0)
                rundist <= 2'd1;
            else if (rundist < 2'd3)
                rundist <= rundist + 2'd1;
            else
                rundist <= 2'd3;
        end
    end

    wire mask0 = (rundist < 2'd3);
    wire mask1 = (rundist < 2'd2);

    wire signed [PIX_W:0] zero9 = {(PIX_W+1){1'b0}};
    wire signed [PIX_W:0] x00 = mask0 ? zero9 : $signed({1'b0, w00});
    wire signed [PIX_W:0] x10 = mask0 ? zero9 : $signed({1'b0, w10});
    wire signed [PIX_W:0] x20 = mask0 ? zero9 : $signed({1'b0, w20});

    wire signed [PIX_W:0] x01 = mask1 ? zero9 : $signed({1'b0, w01});
    wire signed [PIX_W:0] x11 = mask1 ? zero9 : $signed({1'b0, w11});
    wire signed [PIX_W:0] x21 = mask1 ? zero9 : $signed({1'b0, w21});

    wire signed [PIX_W:0] x02 = $signed({1'b0, w02});
    wire signed [PIX_W:0] x12 = $signed({1'b0, w12});
    wire signed [PIX_W:0] x22 = $signed({1'b0, w22});

    //-------------------------------------------------------------------------
    // S1 : nine products
    //-------------------------------------------------------------------------
    reg signed [PROD_W-1:0] p0, p1, p2, p3, p4, p5, p6, p7, p8;

    always @(posedge clk) begin
        p0 <= x00 * c0;  p1 <= x01 * c1;  p2 <= x02 * c2;
        p3 <= x10 * c3;  p4 <= x11 * c4;  p5 <= x12 * c5;
        p6 <= x20 * c6;  p7 <= x21 * c7;  p8 <= x22 * c8;
    end

    always @(posedge clk) win_valid_q <= (rst || frame_rst) ? 1'b0 : win_valid;
    always @(posedge clk) v1          <= (rst || frame_rst) ? 1'b0 : win_valid_q;

    //-------------------------------------------------------------------------
    // S2 : three row sums
    //-------------------------------------------------------------------------
    reg signed [ACC_W-1:0] rs0, rs1, rs2;

    always @(posedge clk) begin
        rs0 <= p0 + p1 + p2;
        rs1 <= p3 + p4 + p5;
        rs2 <= p6 + p7 + p8;
    end

    always @(posedge clk) v2 <= (rst || frame_rst) ? 1'b0 : v1;

    //-------------------------------------------------------------------------
    // S3 : total, saturate, optional ReLU
    //-------------------------------------------------------------------------
    wire signed [ACC_W-1:0] total = rs0 + rs1 + rs2;

    wire signed [OUT_W-1:0] sat =
        (total > $signed({{(ACC_W-OUT_W){1'b0}}, SAT_MAX})) ? SAT_MAX :
        (total < $signed({{(ACC_W-OUT_W){1'b1}}, SAT_MIN})) ? SAT_MIN :
                                                             total[OUT_W-1:0];

    wire signed [OUT_W-1:0] relu_out = (relu_en && sat[OUT_W-1]) ? {OUT_W{1'b0}} : sat;

    always @(posedge clk) begin
        if (rst || frame_rst) begin
            out_valid <= 1'b0;
            out_pixel <= {OUT_W{1'b0}};
        end else begin
            out_valid <= v2;
            out_pixel <= relu_out;
        end
    end
endmodule
`default_nettype wire
