//=============================================================================
// uart_tx.v  -  8N1 UART transmitter
//=============================================================================
`timescale 1ns / 1ps
`default_nettype none

module uart_tx #(
    parameter integer CLKS_PER_BIT = 868
)(
    input  wire       clk,
    input  wire       rst,
    input  wire       tx_start,   // 1-cycle strobe, ignored while busy
    input  wire [7:0] tx_data,
    output reg        tx,
    output reg        tx_busy,
    output reg        tx_done     // 1-cycle strobe at end of stop bit
);
    localparam S_IDLE = 2'd0, S_START = 2'd1, S_DATA = 2'd2, S_STOP = 2'd3;

    reg [1:0]  state;
    reg [15:0] clk_cnt;
    reg [2:0]  bit_idx;
    reg [7:0]  shreg;

    always @(posedge clk) begin
        if (rst) begin
            state   <= S_IDLE;
            tx      <= 1'b1;      // idle high
            tx_busy <= 1'b0;
            tx_done <= 1'b0;
            clk_cnt <= 16'd0;
            bit_idx <= 3'd0;
        end else begin
            tx_done <= 1'b0;
            case (state)
                S_IDLE: begin
                    tx      <= 1'b1;
                    clk_cnt <= 16'd0;
                    bit_idx <= 3'd0;
                    if (tx_start) begin
                        shreg   <= tx_data;
                        tx_busy <= 1'b1;
                        state   <= S_START;
                    end else begin
                        tx_busy <= 1'b0;
                    end
                end

                S_START: begin
                    tx <= 1'b0;
                    if (clk_cnt < CLKS_PER_BIT-1) clk_cnt <= clk_cnt + 1'b1;
                    else begin clk_cnt <= 16'd0; state <= S_DATA; end
                end

                S_DATA: begin
                    tx <= shreg[bit_idx];
                    if (clk_cnt < CLKS_PER_BIT-1) begin
                        clk_cnt <= clk_cnt + 1'b1;
                    end else begin
                        clk_cnt <= 16'd0;
                        if (bit_idx == 3'd7) begin
                            bit_idx <= 3'd0;
                            state   <= S_STOP;
                        end else begin
                            bit_idx <= bit_idx + 1'b1;
                        end
                    end
                end

                S_STOP: begin
                    tx <= 1'b1;
                    if (clk_cnt < CLKS_PER_BIT-1) begin
                        clk_cnt <= clk_cnt + 1'b1;
                    end else begin
                        clk_cnt <= 16'd0;
                        tx_done <= 1'b1;
                        tx_busy <= 1'b0;
                        state   <= S_IDLE;
                    end
                end
            endcase
        end
    end
endmodule

`default_nettype wire
