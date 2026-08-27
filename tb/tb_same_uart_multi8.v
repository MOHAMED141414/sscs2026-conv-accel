`timescale 1ns/1ps
module tb_same_uart_multi8;
    localparam IMG_W=8,IMG_H=8,N=3,CPB=4,NPIX=IMG_W*IMG_H;
    reg clk=0,rst=1,relu_en=0;
    always #5 clk=~clk;
    reg host_tx=1'b1; wire dut_tx,busy_led,done_led;
    conv_top #(.IMG_W(IMG_W),.IMG_H(IMG_H),.N(N),.CLKS_PER_BIT(CPB))
      dut(.clk(clk),.rst(rst),.relu_en(relu_en),
          .uart_rx(host_tx),.uart_tx(dut_tx),.busy_led(busy_led),.done_led(done_led));
    reg [7:0] img[0:NPIX-1],ker1[0:8],ker2[0:8];
    reg [15:0] exp1[0:NPIX-1],exp2[0:NPIX-1];
    integer i,errors,oc;
    reg [7:0] bh,bl; reg signed[15:0] got;
    task send(input [7:0] d); integer k;
        begin host_tx=0; repeat(CPB) @(posedge clk);
          for(k=0;k<8;k=k+1) begin host_tx=d[k]; repeat(CPB) @(posedge clk); end
          host_tx=1; repeat(CPB) @(posedge clk); end endtask
    task recv(output [7:0] d); integer k;
        begin @(negedge dut_tx); repeat(CPB+CPB/2) @(posedge clk);
          for(k=0;k<8;k=k+1) begin d[k]=dut_tx; repeat(CPB) @(posedge clk); end
        end endtask
    initial begin
        errors=0;
        $readmemh("vectors_same_hw/img8_test.hex",img);
        $readmemh("vectors/kernel_sobel_x.hex",ker1);
        $readmemh("vectors/kernel_laplacian.hex",ker2);
        $readmemh("vectors_same_hw/exp8_sobel_x.hex",exp1);
        $readmemh("vectors_same_hw/exp8_laplacian.hex",exp2);
        repeat(10) @(posedge clk); rst=0; repeat(10) @(posedge clk);

        for(i=0;i<9;i=i+1) send(ker1[i]);
        oc=0;
        for(i=0;i<NPIX;i=i+1) begin
            send(img[i]); recv(bh); recv(bl);
            got=$signed({bh,bl});
            if(got!==$signed(exp1[oc])) begin
                $display("P1 MISMATCH %0d: got %0d exp %0d",oc,got,$signed(exp1[oc]));
                errors=errors+1;
            end
            oc=oc+1;
        end
        $display("Pass 1 (sobel_x, 8x8): %0d/%0d, errors=%0d, done_led=%0b",oc,NPIX,errors,done_led);

        for(i=0;i<9;i=i+1) send(ker2[i]);
        oc=0;
        for(i=0;i<NPIX;i=i+1) begin
            send(img[i]); recv(bh); recv(bl);
            got=$signed({bh,bl});
            if(got!==$signed(exp2[oc])) begin
                $display("P2 MISMATCH %0d: got %0d exp %0d",oc,got,$signed(exp2[oc]));
                errors=errors+1;
            end
            oc=oc+1;
        end
        $display("Pass 2 (laplacian, 8x8): %0d/%0d, total errors=%0d, done_led=%0b",oc,NPIX,errors,done_led);
        $display("----------------------------------------------");
        if(errors==0) $display("PASS  multi-kernel over UART, zero-gap, both passes bit-exact");
        else           $display("FAIL  %0d total errors",errors);
        $display("----------------------------------------------");
        $finish;
    end
    initial begin #10000000; $display("FAIL: timeout"); $finish; end
endmodule
