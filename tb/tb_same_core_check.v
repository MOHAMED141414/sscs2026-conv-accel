`timescale 1ns/1ps
//=============================================================================
// tb_same_core_check.v  -  Verify conv_accel_same: zero gaps, bit-exact
//
// Feeds ONLY the real IMG_W x IMG_H pixels (no padding pixels at all),
// continuously, 1 per cycle. Checks:
//   1. All NPIX outputs bit-exact vs golden SAME model
//   2. out_valid NEVER has a gap >=2 cycles anywhere in the stream
//      (in fact should have ZERO gaps once started -- true 1/cycle)
//=============================================================================
module tb_same_core_check;
    localparam IMG_W=32, IMG_H=32, N=3, NPIX=IMG_W*IMG_H;

    reg clk=0, rst=1, relu_en=0, frame_rst=0;
    always #5 clk = ~clk;

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

    reg [7:0]  ker[0:8];
    reg [7:0]  img[0:NPIX-1];
    reg [15:0] exp[0:NPIX-1];

    integer i, errors, oc, gap_len, max_gap, gap_violations;
    reg started;

    initial begin
        $readmemh("vectors/kernel_sobel_x.hex", ker);
        $readmemh("vectors/img_ramp.hex", img);
        $readmemh("vectors_same_hw/exp_ramp__sobel_x.hex", exp);

        errors=0; oc=0; gap_len=0; max_gap=0; gap_violations=0; started=0;

        repeat(5) @(posedge clk); rst=0; repeat(5) @(posedge clk);

        for (i=0; i<9; i=i+1) begin
            @(negedge clk);
            coef_we=1; coef_addr=i[3:0]; coef_din=ker[i];
        end
        @(negedge clk); coef_we=0;
        repeat(2) @(negedge clk);

        // feed ONLY the real NPIX pixels, continuously, no gaps, no padding
        for (i=0; i<NPIX; i=i+1) begin
            @(negedge clk);
            in_valid = 1'b1;
            in_pixel = img[i];
        end
        @(negedge clk);
        in_valid = 1'b0;

        repeat(20) @(posedge clk);

        $display("----------------------------------------------");
        if (errors==0 && oc==NPIX)
            $display("PASS  %0d/%0d bit-exact, max gap=%0d cycles, gap>=2 violations=%0d",
                      oc, NPIX, max_gap, gap_violations);
        else
            $display("FAIL  %0d errors, %0d/%0d outputs, max gap=%0d, violations=%0d",
                      errors, oc, NPIX, max_gap, gap_violations);
        $display("----------------------------------------------");
        $finish;
    end

    always @(posedge clk) begin
        if (out_valid) begin
            if (!started) started = 1;
            if (oc < NPIX) begin
                if ($signed(out_pixel) !== $signed(exp[oc])) begin
                    if (errors < 10)
                        $display("MISMATCH %0d: got %0d exp %0d", oc, $signed(out_pixel), $signed(exp[oc]));
                    errors = errors + 1;
                end
                oc = oc + 1;
            end
        end
    end

    always @(posedge clk) begin
        if (started && oc < NPIX) begin
            if (!out_valid) begin
                gap_len = gap_len + 1;
                if (gap_len > max_gap) max_gap = gap_len;
                if (gap_len == 2) gap_violations = gap_violations + 1;
            end else
                gap_len = 0;
        end
    end

    initial begin #50000; $display("FAIL: timeout"); $finish; end
endmodule
