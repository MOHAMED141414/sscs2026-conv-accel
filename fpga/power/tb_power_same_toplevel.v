`timescale 1ns / 1ps
//=============================================================================
// tb_power_same_toplevel.v  -  SAIF trace against the POST-ROUTE netlist
// (SAME zero-gap build)
//=============================================================================
module tb_power_same_toplevel;
    localparam IMG_W=32, IMG_H=32, N=3, CPB=868;  // MUST match the netlist's real synthesized baud divider
    localparam NPIX_FULL = IMG_W*IMG_H;
    localparam NPIX = 16;  // representative window: 2.5 rows, real UART timing

    reg clk=0, rst=1, relu_en=0;
    always #5 clk = ~clk;

    reg  host_tx = 1'b1;
    wire dut_tx, busy_led, done_led;

    conv_top dut (
        .clk(clk), .rst(rst), .relu_en(relu_en),
        .uart_rx(host_tx), .uart_tx(dut_tx),
        .busy_led(busy_led), .done_led(done_led));

    reg [7:0] img[0:NPIX_FULL-1], ker[0:8];  // full image loaded, only first NPIX streamed
    integer i;
    reg [7:0] bh, bl;

    task send(input [7:0] d);
        integer k;
        begin
            host_tx = 0; repeat(CPB) @(posedge clk);
            for (k=0;k<8;k=k+1) begin host_tx=d[k]; repeat(CPB) @(posedge clk); end
            host_tx = 1; repeat(CPB) @(posedge clk);
        end
    endtask

    task recv(output [7:0] d);
        integer k;
        begin
            @(negedge dut_tx); repeat(CPB+CPB/2) @(posedge clk);
            for (k=0;k<8;k=k+1) begin d[k]=dut_tx; repeat(CPB) @(posedge clk); end
        end
    endtask

    initial begin
        $readmemh("vectors/kernel_sobel_x.hex", ker);
        $readmemh("vectors/img_ramp.hex", img);

        repeat(10) @(posedge clk);
        rst = 0;
        repeat(10) @(posedge clk);

        for (i=0; i<9; i=i+1) send(ker[i]);
        for (i=0; i<NPIX; i=i+1) begin
            send(img[i]);
            recv(bh); recv(bl);
        end

        repeat(20) @(posedge clk);
        $display("Post-route power trace complete: %0d pixels, zero-gap, through full UART protocol", NPIX);
        $finish;
    end

    initial begin #500000000; $display("TIMEOUT"); $finish; end
endmodule
