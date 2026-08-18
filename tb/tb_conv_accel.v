//=============================================================================
// tb_conv_accel.v  -  Self-checking testbench
//
// Loads an image + kernel + expected-output file produced by conv_golden.py,
// streams the image through conv_accel, and compares every output pixel
// against the golden reference.
//
// Run:
//   iverilog -o sim conv_accel.v tb_conv_accel.v
//   vvp sim +IMG=vectors/img_random.hex \
//           +KER=vectors/kernel_sobel_x.hex \
//           +EXP=vectors/exp_random__sobel_x.hex \
//           +RELU=0
//=============================================================================

`timescale 1ns / 1ps

module tb_conv_accel;

    localparam integer IMG_W = 32;
    localparam integer IMG_H = 32;
    localparam integer N     = 3;
    localparam integer OUT_W = IMG_W - N + 1;
    localparam integer OUT_H = IMG_H - N + 1;
    localparam integer NPIX  = IMG_W * IMG_H;
    localparam integer NOUT  = OUT_W * OUT_H;

    reg clk = 0, rst = 1;
    always #5 clk = ~clk;              // 100 MHz

    reg               coef_we   = 0;
    reg  [3:0]        coef_addr = 0;
    reg  signed [7:0] coef_din  = 0;
    reg               relu_en   = 0;
    reg               in_valid  = 0;
    reg  [7:0]        in_pixel  = 0;

    wire               out_valid;
    wire signed [15:0] out_pixel;

    conv_accel #(
        .IMG_W(IMG_W), .IMG_H(IMG_H), .N(N)
    ) dut (
        .clk(clk), .rst(rst),
        .coef_we(coef_we), .coef_addr(coef_addr), .coef_din(coef_din),
        .relu_en(relu_en), .frame_rst(1'b0),
        .in_valid(in_valid), .in_pixel(in_pixel),
        .out_valid(out_valid), .out_pixel(out_pixel)
    );

    // ---- storage ----------------------------------------------------------
    reg  [7:0]        img [0:NPIX-1];
    reg  [7:0]        ker [0:N*N-1];
    reg  [15:0]       exp [0:NOUT-1];
    reg signed [15:0] got [0:NOUT-1];

    integer i, errors, ocount, relu_i;
    reg [1023:0] f_img, f_ker, f_exp;   // 128 chars - must exceed longest path

    // ---- capture outputs --------------------------------------------------
    always @(posedge clk) begin
        if (out_valid && !rst) begin
            if (ocount < NOUT) got[ocount] <= out_pixel;
            ocount <= ocount + 1;
        end
    end

    initial begin
        errors = 0;
        ocount = 0;

        if (!$value$plusargs("IMG=%s", f_img)) begin
            $display("ERROR: need +IMG=<file>"); $finish;
        end
        if (!$value$plusargs("KER=%s", f_ker)) begin
            $display("ERROR: need +KER=<file>"); $finish;
        end
        if (!$value$plusargs("EXP=%s", f_exp)) begin
            $display("ERROR: need +EXP=<file>"); $finish;
        end
        if (!$value$plusargs("RELU=%d", relu_i)) relu_i = 0;

        $readmemh(f_img, img);
        $readmemh(f_ker, ker);
        $readmemh(f_exp, exp);

        if ($test$plusargs("DUMP")) begin
            $dumpfile("conv_accel.vcd");
            $dumpvars(0, tb_conv_accel);
        end

        relu_en = relu_i[0];

        // reset
        repeat (4) @(posedge clk);
        rst = 0;
        @(posedge clk);

        // load kernel coefficients
        for (i = 0; i < N*N; i = i + 1) begin
            @(negedge clk);
            coef_we   = 1;
            coef_addr = i[3:0];
            coef_din  = ker[i];
        end
        @(negedge clk);
        coef_we = 0;

        repeat (2) @(posedge clk);

        // stream the image, one pixel per cycle, no gaps
        for (i = 0; i < NPIX; i = i + 1) begin
            @(negedge clk);
            in_valid = 1;
            in_pixel = img[i];
        end
        @(negedge clk);
        in_valid = 0;

        // flush the pipeline
        repeat (10) @(posedge clk);

        // ---- compare ------------------------------------------------------
        if (ocount != NOUT) begin
            $display("FAIL: produced %0d outputs, expected %0d", ocount, NOUT);
            errors = errors + 1;
        end

        for (i = 0; i < NOUT; i = i + 1) begin
            if (got[i] !== $signed(exp[i])) begin
                if (errors < 10)
                    $display("  MISMATCH idx %0d (row %0d col %0d): got %0d, exp %0d",
                             i, i/OUT_W, i%OUT_W, got[i], $signed(exp[i]));
                errors = errors + 1;
            end
        end

        $display("---------------------------------------------------------");
        if (errors == 0)
            $display("PASS  %0d/%0d pixels bit-exact   [%0s | relu=%0d]",
                     NOUT, NOUT, f_exp, relu_i);
        else
            $display("FAIL  %0d errors of %0d           [%0s | relu=%0d]",
                     errors, NOUT, f_exp, relu_i);
        $display("---------------------------------------------------------");

        $finish;
    end

    // watchdog
    initial begin
        #500000;
        $display("FAIL: timeout");
        $finish;
    end

endmodule
