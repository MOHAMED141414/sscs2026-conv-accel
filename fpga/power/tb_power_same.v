`timescale 1ns / 1ps
//=============================================================================
// tb_power_same.v  -  SAIF-ready activity trace for the SAME zero-gap core
//
// Same methodology as tb_power_valid.v: drives conv_accel_same directly,
// reset+coef-load excluded from the dump, dumping stops immediately after
// pipeline drain (no idle tail). This window is 1024 real pixels with
// zero-gap out_valid throughout -- the busiest possible activity profile
// for this core, since every single cycle toggles the datapath.
//
// Convert to SAIF with:
//   vcd2saif -input power_same.vcd -output power_same.saif
//=============================================================================
module tb_power_same;
    localparam IMG_W=32, IMG_H=32, N=3;
    localparam NPIX = IMG_W*IMG_H;   // 1024, every pixel produces one output

    reg clk=0, rst=1, relu_en=0, frame_rst=0;
    always #5 clk = ~clk;   // 100 MHz, matches target operating frequency

    reg               coef_we=0;
    reg  [3:0]        coef_addr=0;
    reg  signed [7:0] coef_din=0;
    reg               in_valid=0;
    reg  [7:0]        in_pixel=0;
    wire              out_valid;
    wire signed [15:0] out_pixel;

    conv_accel_same #(.IMG_W(IMG_W), .IMG_H(IMG_H), .N(N)) dut (
        .clk(clk), .rst(rst),
        .coef_we(coef_we), .coef_addr(coef_addr), .coef_din(coef_din),
        .relu_en(relu_en), .frame_rst(frame_rst),
        .in_valid(in_valid), .in_pixel(in_pixel),
        .out_valid(out_valid), .out_pixel(out_pixel));

    reg [7:0] ker[0:8], img[0:NPIX-1];
    integer i, oc;

    initial begin
        $readmemh("vectors/kernel_sobel_x.hex", ker);
        $readmemh("vectors/img_ramp.hex", img);

        // ---- reset and coefficient-load prologue: NOT dumped -------------
        repeat(5) @(posedge clk);
        rst = 0;
        repeat(2) @(posedge clk);

        // ---- dumping starts here -------------------------------------------
        $dumpfile("power_same.vcd");
        $dumpvars(0, tb_power_same);

        for (i=0; i<9; i=i+1) begin
            @(negedge clk);
            coef_we=1; coef_addr=i[3:0]; coef_din=ker[i];
        end
        @(negedge clk); coef_we=0;
        repeat(2) @(negedge clk);

        oc = 0;
        for (i=0; i<NPIX; i=i+1) begin
            @(negedge clk);
            in_valid = 1'b1;
            in_pixel = img[i];
        end
        @(negedge clk);
        in_valid = 1'b0;

        repeat(6) @(posedge clk);
        $display("SAIF window: reset+coef-load excluded, %0d pixels streamed (zero-gap), dump ends at pipeline drain", NPIX);
        $dumpoff;
        $finish;
    end

    always @(posedge clk) if (out_valid) oc = oc + 1;
endmodule
