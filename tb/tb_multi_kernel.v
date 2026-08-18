//=============================================================================
// tb_multi_kernel.v - Multi-kernel bonus verification
//
// Runs TWO kernels back-to-back on the same image without a hardware reset,
// verifying that the FSM loops from S_DONE back to S_COEF and the core's
// frame_rst properly resets the position counters between passes.
//
// Run:
//   iverilog -g2012 -o build/multi.vvp rtl/conv_accel.v rtl/uart_rx.v \
//            rtl/uart_tx.v rtl/conv_top.v tb/tb_multi_kernel.v
//   vvp build/multi.vvp
//=============================================================================
`timescale 1ns / 1ps

module tb_multi_kernel;

    localparam integer IMG_W = 32, IMG_H = 32, N = 3;
    localparam integer OW = IMG_W-N+1, OH = IMG_H-N+1;
    localparam integer NPIX = IMG_W*IMG_H, NOUT = OW*OH;
    localparam integer CPB  = 4;      // fast UART for sim speed

    reg clk = 0, rst = 1, relu_en = 0;
    always #5 clk = ~clk;

    reg  host_tx = 1'b1;
    wire dut_tx, busy_led, done_led;

    conv_top #(.IMG_W(IMG_W), .IMG_H(IMG_H), .N(N), .CLKS_PER_BIT(CPB))
      dut (.clk(clk), .rst(rst), .relu_en(relu_en),
           .uart_rx(host_tx), .uart_tx(dut_tx),
           .busy_led(busy_led), .done_led(done_led));

    // ---- storage ----------------------------------------------------------
    reg [7:0]  img [0:NPIX-1];
    reg [7:0]  ker1 [0:N*N-1];
    reg [7:0]  ker2 [0:N*N-1];
    reg [15:0] exp1 [0:NOUT-1];
    reg [15:0] exp2 [0:NOUT-1];

    integer i, r, c, errors, ocount;
    reg [7:0]  b_hi, b_lo;
    reg signed [15:0] got;

    // ---- UART bit-bang ----------------------------------------------------
    task host_send(input [7:0] d);
        integer k;
        begin
            host_tx = 1'b0;
            repeat (CPB) @(posedge clk);
            for (k = 0; k < 8; k = k + 1) begin
                host_tx = d[k];
                repeat (CPB) @(posedge clk);
            end
            host_tx = 1'b1;
            repeat (CPB) @(posedge clk);
        end
    endtask

    task host_recv(output [7:0] d);
        integer k;
        begin
            @(negedge dut_tx);
            repeat (CPB + CPB/2) @(posedge clk);
            for (k = 0; k < 8; k = k + 1) begin
                d[k] = dut_tx;
                repeat (CPB) @(posedge clk);
            end
        end
    endtask

    // ---- run one kernel pass and check against expected -------------------
    task run_pass(
        input [8*9-1:0] ker_flat,  // 9 bytes packed
        input integer    pass_num
    );
        integer ii, rr, cc, err_cnt, oc;
        reg [7:0] bh, bl;
        reg signed [15:0] g;
        begin
            err_cnt = 0;
            oc = 0;

            // 1) send kernel
            for (ii = 0; ii < N*N; ii = ii + 1)
                host_send(ker_flat[ii*8 +: 8]);

            // 2) send pixels with inline readback
            for (ii = 0; ii < NPIX; ii = ii + 1) begin
                rr = ii / IMG_W;
                cc = ii % IMG_W;
                host_send(img[ii]);
                if (rr >= N-1 && cc >= N-1) begin
                    host_recv(bh);
                    host_recv(bl);
                    g = $signed({bh, bl});
                    if (pass_num == 1) begin
                        if (g !== $signed(exp1[oc])) err_cnt = err_cnt + 1;
                    end else begin
                        if (g !== $signed(exp2[oc])) err_cnt = err_cnt + 1;
                    end
                    oc = oc + 1;
                end
            end

            // 3) wait for done_led
            repeat (200) @(posedge clk);

            $display("  Pass %0d: %0d/%0d pixels, %0d errors, done_led=%0b",
                     pass_num, oc, NOUT, err_cnt, done_led);
            errors = errors + err_cnt;
            if (oc != NOUT) errors = errors + 1;
        end
    endtask

    // ---- main -------------------------------------------------------------
    reg [8*9-1:0] k1_flat, k2_flat;
    initial begin
        errors = 0;

        // load test data
        $readmemh("vectors/img_ramp.hex", img);
        $readmemh("vectors/kernel_sobel_x.hex", ker1);
        $readmemh("vectors/kernel_laplacian.hex", ker2);
        $readmemh("vectors/exp_ramp__sobel_x.hex", exp1);
        $readmemh("vectors/exp_ramp__laplacian.hex", exp2);

        // pack kernels into flat bit vectors for the task
        for (i = 0; i < 9; i = i + 1) begin
            k1_flat[i*8 +: 8] = ker1[i];
            k2_flat[i*8 +: 8] = ker2[i];
        end

        // reset
        repeat (10) @(posedge clk);
        rst = 0;
        repeat (10) @(posedge clk);

        $display("=== Multi-kernel test: two passes, no hardware reset ===");

        run_pass(k1_flat, 1);    // Sobel X
        run_pass(k2_flat, 2);    // Laplacian — should work without reset

        $display("---------------------------------------------------------");
        if (errors == 0)
            $display("PASS  both passes bit-exact, multi-kernel verified");
        else
            $display("FAIL  %0d total errors", errors);
        $display("---------------------------------------------------------");
        $finish;
    end

    // watchdog
    initial begin #100000000; $display("FAIL: timeout"); $finish; end

endmodule
