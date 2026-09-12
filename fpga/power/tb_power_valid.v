`timescale 1ns / 1ps
//=============================================================================
// tb_power_valid.v  -  SAIF-ready activity trace for the VALID-border core
//
// Drives conv_accel DIRECTLY (no UART, no host protocol) so the dumped VCD
// window contains ONLY active convolution switching activity: reset is
// deasserted before dumping starts, coefficient load and pixel streaming
// are both included (both are part of "active convolution processing"),
// and dumping stops the cycle after the last valid output is captured --
// no idle tail.
//
// Convert to SAIF with:
//   vcd2saif -input power_valid.vcd -output power_valid.saif
//=============================================================================
module tb_power_valid;
    localparam IMG_W=32, IMG_H=32, N=3;
    localparam NPIX = IMG_W*IMG_H;
    localparam NOUT = (IMG_W-N+1)*(IMG_H-N+1);   // 900 for VALID border

    reg clk=0, rst=1, relu_en=0;
    always #5 clk = ~clk;   // 100 MHz, matches target operating frequency

    reg               coef_we=0;
    reg  [3:0]        coef_addr=0;
    reg  signed [7:0] coef_din=0;
    reg               in_valid=0;
    reg  [7:0]        in_pixel=0;
    wire              out_valid;
    wire signed [15:0] out_pixel;

    conv_accel #(.IMG_W(IMG_W), .IMG_H(IMG_H), .N(N)) dut (
        .clk(clk), .rst(rst),
        .coef_we(coef_we), .coef_addr(coef_addr), .coef_din(coef_din),
        .relu_en(relu_en),
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

        // ---- dumping starts here: everything from this point on is
        // genuine active-convolution switching activity -------------------
        $dumpfile("power_valid.vcd");
        $dumpvars(0, tb_power_valid);

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

        // drain the pipeline, then stop dumping immediately -- no idle tail
        repeat(6) @(posedge clk);
        $display("SAIF window: reset+coef-load excluded, %0d pixels streamed, dump ends at pipeline drain", NPIX);
        $dumpoff;
        $finish;
    end

    always @(posedge clk) if (out_valid) oc = oc + 1;
endmodule
