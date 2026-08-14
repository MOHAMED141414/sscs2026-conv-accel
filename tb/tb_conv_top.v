//=============================================================================
// tb_conv_top.v  -  System-level test over the UART interface
//
//   iverilog -g2012 -o build/top.vvp rtl/conv_accel.v rtl/uart_rx.v \
//            rtl/uart_tx.v rtl/conv_top.v tb/tb_conv_top.v
//   vvp build/top.vvp +IMG=vectors/img_ramp.hex \
//                     +KER=vectors/kernel_sobel_x.hex \
//                     +EXP=vectors/exp_ramp__sobel_x.hex +RELU=0
//=============================================================================
`timescale 1ns / 1ps

module tb_conv_top;

    localparam integer IMG_W = 32, IMG_H = 32, N = 3;
    localparam integer OW = IMG_W-N+1, OH = IMG_H-N+1;
    localparam integer NPIX = IMG_W*IMG_H, NOUT = OW*OH;
    localparam integer CPB  = 4;      // tiny divisor so the sim finishes fast

    reg clk = 0, rst = 1, relu_en = 0;
    always #5 clk = ~clk;

    reg  host_tx = 1'b1;
    wire dut_tx, busy_led, done_led;

    conv_top #(.IMG_W(IMG_W), .IMG_H(IMG_H), .N(N), .CLKS_PER_BIT(CPB))
      dut (.clk(clk), .rst(rst), .relu_en(relu_en),
           .uart_rx(host_tx), .uart_tx(dut_tx),
           .busy_led(busy_led), .done_led(done_led));

    reg [7:0]  img [0:NPIX-1];
    reg [7:0]  ker [0:N*N-1];
    reg [15:0] exp [0:NOUT-1];

    integer i, r, c, errors, ocount, relu_i;
    reg [1023:0] f_img, f_ker, f_exp;
    reg [7:0]  b_hi, b_lo;
    reg signed [15:0] got;

    // ---- host-side UART bit-banging ---------------------------------------
    task host_send(input [7:0] d);
        integer k;
        begin
            host_tx = 1'b0;                       // start
            repeat (CPB) @(posedge clk);
            for (k = 0; k < 8; k = k + 1) begin
                host_tx = d[k];                   // LSB first
                repeat (CPB) @(posedge clk);
            end
            host_tx = 1'b1;                       // stop
            repeat (CPB) @(posedge clk);
        end
    endtask

    task host_recv(output [7:0] d);
        integer k;
        begin
            @(negedge dut_tx);                    // start bit
            repeat (CPB + CPB/2) @(posedge clk);  // to middle of bit 0
            for (k = 0; k < 8; k = k + 1) begin
                d[k] = dut_tx;
                repeat (CPB) @(posedge clk);
            end
        end
    endtask

    initial begin
        errors = 0; ocount = 0;
        if (!$value$plusargs("IMG=%s", f_img)) begin $display("need +IMG"); $finish; end
        if (!$value$plusargs("KER=%s", f_ker)) begin $display("need +KER"); $finish; end
        if (!$value$plusargs("EXP=%s", f_exp)) begin $display("need +EXP"); $finish; end
        if (!$value$plusargs("RELU=%d", relu_i)) relu_i = 0;

        $readmemh(f_img, img);
        $readmemh(f_ker, ker);
        $readmemh(f_exp, exp);
        relu_en = relu_i[0];

        repeat (10) @(posedge clk);
        rst = 0;
        repeat (10) @(posedge clk);

        // 1) kernel
        for (i = 0; i < N*N; i = i + 1) host_send(ker[i]);

        // 2) pixels, reading back results where a window completes
        for (i = 0; i < NPIX; i = i + 1) begin
            r = i / IMG_W;
            c = i % IMG_W;
            host_send(img[i]);
            if (r >= N-1 && c >= N-1) begin
                host_recv(b_hi);
                host_recv(b_lo);
                got = $signed({b_hi, b_lo});
                if (got !== $signed(exp[ocount])) begin
                    if (errors < 8)
                        $display("  MISMATCH out %0d (r%0d c%0d): got %0d exp %0d",
                                 ocount, ocount/OW, ocount%OW, got, $signed(exp[ocount]));
                    errors = errors + 1;
                end
                ocount = ocount + 1;
            end
        end

        repeat (200) @(posedge clk);

        if (ocount != NOUT) begin
            $display("FAIL: got %0d outputs, expected %0d", ocount, NOUT);
            errors = errors + 1;
        end
        if (!done_led) begin
            $display("FAIL: done_led never asserted");
            errors = errors + 1;
        end

        $display("---------------------------------------------------------");
        if (errors == 0)
            $display("PASS  %0d/%0d over UART, done_led set   [%0s]", ocount, NOUT, f_exp);
        else
            $display("FAIL  %0d errors                        [%0s]", errors, f_exp);
        $display("---------------------------------------------------------");
        $finish;
    end

    initial begin
        #50000000;
        $display("FAIL: timeout (state=%0d pix=%0d out=%0d)",
                 dut.state, dut.pix_cnt, ocount);
        $finish;
    end
endmodule
