`timescale 1ns/1ps
// Two-pass test: Sobel X then Laplacian, verifying frame_rst correctly
// clears the line buffers, window masking state, and pipeline between passes.
module tb_same_multi;
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

    reg [7:0]  ker1[0:8], ker2[0:8], img[0:NPIX-1];
    reg [15:0] exp1[0:NPIX-1], exp2[0:NPIX-1];
    integer i, errors1, errors2, oc;

    task load_kernel(input integer which);
        integer k;
        begin
            for (k=0; k<9; k=k+1) begin
                @(negedge clk);
                coef_we=1; coef_addr=k[3:0];
                coef_din = (which==1) ? ker1[k] : ker2[k];
            end
            @(negedge clk); coef_we=0;
            repeat(2) @(negedge clk);
        end
    endtask

    task run_pass(input integer which);
        integer k;
        begin
            oc=0;
            for (k=0; k<NPIX; k=k+1) begin
                @(negedge clk);
                in_valid=1; in_pixel=img[k];
            end
            @(negedge clk); in_valid=0;
            repeat(20) @(posedge clk);
        end
    endtask

    initial begin
        $readmemh("vectors/kernel_sobel_x.hex", ker1);
        $readmemh("vectors/kernel_laplacian.hex", ker2);
        $readmemh("vectors/img_ramp.hex", img);
        $readmemh("vectors_same_hw/exp_ramp__sobel_x.hex", exp1);
        $readmemh("vectors_same_hw/exp_ramp__laplacian.hex", exp2);

        errors1=0; errors2=0; oc=0;
        repeat(5) @(posedge clk); rst=0; repeat(5) @(posedge clk);

        // pass 1: sobel_x
        load_kernel(1);
        oc=0;
        fork
            run_pass(1);
        join
        $display("Pass 1 (sobel_x): fed %0d pixels", NPIX);

        // pulse frame_rst between passes (mimics conv_top's S_DONE behavior)
        @(negedge clk); frame_rst=1;
        @(negedge clk); frame_rst=0;
        repeat(5) @(negedge clk);

        // pass 2: laplacian, NO hardware reset
        load_kernel(2);
        run_pass(2);
        $display("Pass 2 (laplacian): fed %0d pixels", NPIX);

        $display("----------------------------------------------");
        $display("errors1=%0d errors2=%0d (see capture logic below)", errors1, errors2);
        $display("----------------------------------------------");
        $finish;
    end

    // capture + check against the ACTIVE pass's golden vector
    integer pass_num = 0, cap_idx = 0;
    always @(posedge clk) begin
        if (out_valid) begin
            if (pass_num == 1 && cap_idx < NPIX) begin
                if ($signed(out_pixel) !== $signed(exp1[cap_idx])) begin
                    if (errors1<5) $display("P1 MISMATCH %0d: got %0d exp %0d",cap_idx,$signed(out_pixel),$signed(exp1[cap_idx]));
                    errors1=errors1+1;
                end
                cap_idx=cap_idx+1;
            end else if (pass_num==2 && cap_idx<NPIX) begin
                if ($signed(out_pixel) !== $signed(exp2[cap_idx])) begin
                    if (errors2<5) $display("P2 MISMATCH %0d: got %0d exp %0d",cap_idx,$signed(out_pixel),$signed(exp2[cap_idx]));
                    errors2=errors2+1;
                end
                cap_idx=cap_idx+1;
            end
        end
    end

    initial begin
        @(negedge rst);
        pass_num=1; cap_idx=0;
        wait(cap_idx>=NPIX);
        $display("Pass 1 captured %0d outputs, %0d errors", cap_idx, errors1);
        wait(frame_rst==1);
        @(negedge frame_rst);
        pass_num=2; cap_idx=0;
        wait(cap_idx>=NPIX);
        $display("Pass 2 captured %0d outputs, %0d errors", cap_idx, errors2);
        if (errors1==0 && errors2==0)
            $display("MULTI-KERNEL PASS: both passes bit-exact, zero-gap");
        else
            $display("MULTI-KERNEL FAIL");
    end

    initial begin #100000; $display("FAIL: timeout"); $finish; end
endmodule
