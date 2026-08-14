//=============================================================================
// uart_rx.v  -  8N1 UART receiver
// CLKS_PER_BIT = f_clk / baud   (100 MHz / 115200 = 868)
//=============================================================================
`timescale 1ns / 1ps
`default_nettype none

module uart_rx #(
    parameter integer CLKS_PER_BIT = 868
)(
    input  wire       clk,
    input  wire       rst,
    input  wire       rx,
    output reg        rx_valid,   // 1-cycle strobe
    output reg  [7:0] rx_data
);
    localparam S_IDLE = 3'd0, S_START = 3'd1, S_DATA = 3'd2,
               S_STOP = 3'd3, S_DONE  = 3'd4;

    reg [2:0]  state;
    reg [15:0] clk_cnt;
    reg [2:0]  bit_idx;
    reg [7:0]  shreg;

    // two-flop synchroniser on the async input
    reg rx_m, rx_s;
    always @(posedge clk) begin
        rx_m <= rx;
        rx_s <= rx_m;
    end

    always @(posedge clk) begin
        if (rst) begin
            state    <= S_IDLE;
            rx_valid <= 1'b0;
            rx_data  <= 8'd0;
            clk_cnt  <= 16'd0;
            bit_idx  <= 3'd0;
        end else begin
            rx_valid <= 1'b0;
            case (state)
                S_IDLE: begin
                    clk_cnt <= 16'd0;
                    bit_idx <= 3'd0;
                    if (rx_s == 1'b0) state <= S_START;   // start bit edge
                end

                S_START: begin
                    // sample at the middle of the start bit to confirm
                    if (clk_cnt == (CLKS_PER_BIT-1)/2) begin
                        if (rx_s == 1'b0) begin
                            clk_cnt <= 16'd0;
                            state   <= S_DATA;
                        end else begin
                            state <= S_IDLE;              // glitch, abort
                        end
                    end else begin
                        clk_cnt <= clk_cnt + 1'b1;
                    end
                end

                S_DATA: begin
                    if (clk_cnt < CLKS_PER_BIT-1) begin
                        clk_cnt <= clk_cnt + 1'b1;
                    end else begin
                        clk_cnt      <= 16'd0;
                        shreg[bit_idx] <= rx_s;           // LSB first
                        if (bit_idx == 3'd7) begin
                            bit_idx <= 3'd0;
                            state   <= S_STOP;
                        end else begin
                            bit_idx <= bit_idx + 1'b1;
                        end
                    end
                end

                S_STOP: begin
                    if (clk_cnt < CLKS_PER_BIT-1) begin
                        clk_cnt <= clk_cnt + 1'b1;
                    end else begin
                        clk_cnt  <= 16'd0;
                        rx_data  <= shreg;
                        rx_valid <= 1'b1;
                        state    <= S_DONE;
                    end
                end

                S_DONE: state <= S_IDLE;

                default: state <= S_IDLE;
            endcase
        end
    end
endmodule

`default_nettype wire
