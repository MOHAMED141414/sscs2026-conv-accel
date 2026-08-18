//=============================================================================
// conv_top.v  -  Top-level FPGA wrapper for the convolution accelerator
// IEEE SSCS Egypt Chapter 2026 Student Design Competition
//
// HOST PROTOCOL (request-response, no flow-control lines needed):
//   1. Host sends N*N kernel bytes (int8, row-major)
//   2. Host sends IMG_W*IMG_H pixel bytes, ONE AT A TIME.
//      For each pixel that completes a window, the board replies with
//      2 bytes (int16 result, big-endian) before the host sends the next.
//      The host knows which pixels produce output: row>=N-1 && col>=N-1.
//   3. done_led asserts when the full frame has been processed.
//
// WHY NO OUTPUT FIFO: conv_accel gates all state on in_valid, so it is
// stall-tolerant. We advance the pixel stream at UART pace rather than
// buffering 900 results. This keeps BRAM usage at ZERO, which matters
// because the competition FoM charges 100 penalty units per BRAM.
//
// The 1 output-pixel-per-cycle throughput figure is a property of the core
// and is measured there; this wrapper is the demo/verification harness and
// is deliberately limited by the serial link.
//=============================================================================
`timescale 1ns / 1ps
`default_nettype none

module conv_top #(
    parameter integer IMG_W        = 32,
    parameter integer IMG_H        = 32,
    parameter integer N            = 3,
    parameter integer CLKS_PER_BIT = 868   // 100 MHz / 115200 baud
)(
    input  wire       clk,
    input  wire       rst,
    input  wire       relu_en,     // e.g. a board switch
    input  wire       uart_rx,
    output wire       uart_tx,
    output wire       busy_led,
    output reg        done_led
);
    localparam integer TAPS  = N * N;
    localparam integer NPIX  = IMG_W * IMG_H;

    localparam S_COEF   = 3'd0,
               S_RXPIX  = 3'd1,
               S_FEED   = 3'd2,
               S_WAIT   = 3'd3,
               S_TX_HI  = 3'd4,
               S_TX_LO  = 3'd5,
               S_DONE   = 3'd6;

    reg [2:0] state;

    // ---- UART ------------------------------------------------------------
    wire       rx_valid;
    wire [7:0] rx_data;
    reg        tx_start;
    reg  [7:0] tx_data;
    wire       tx_done, tx_busy;

    uart_rx #(.CLKS_PER_BIT(CLKS_PER_BIT)) u_rx (
        .clk(clk), .rst(rst), .rx(uart_rx),
        .rx_valid(rx_valid), .rx_data(rx_data));

    uart_tx #(.CLKS_PER_BIT(CLKS_PER_BIT)) u_tx (
        .clk(clk), .rst(rst),
        .tx_start(tx_start), .tx_data(tx_data),
        .tx(uart_tx), .tx_busy(tx_busy), .tx_done(tx_done));

    // ---- convolution core -------------------------------------------------
    reg                     coef_we;
    reg  [3:0]  coef_addr;   // COEF_AW of the core
    reg  signed [7:0]       coef_din;
    reg                     in_valid;
    reg  [7:0]              in_pixel;
    wire                    out_valid;
    wire signed [15:0]      out_pixel;
    reg                     frame_rst;    // resets core counters between kernel passes

    conv_accel #(.IMG_W(IMG_W), .IMG_H(IMG_H), .N(N)) u_core (
        .clk(clk), .rst(rst),
        .coef_we(coef_we), .coef_addr(coef_addr), .coef_din(coef_din),
        .relu_en(relu_en), .frame_rst(frame_rst),
        .in_valid(in_valid), .in_pixel(in_pixel),
        .out_valid(out_valid), .out_pixel(out_pixel));

    // ---- pending-result capture ------------------------------------------
    // At most one result can be produced per pixel fed, so a single
    // register suffices - no FIFO, no BRAM.
    reg               pend_valid;
    reg signed [15:0] pend_data;
    reg               pend_clr;

    always @(posedge clk) begin
        if (rst) begin
            pend_valid <= 1'b0;
            pend_data  <= 16'd0;
        end else begin
            if (out_valid) begin
                pend_valid <= 1'b1;
                pend_data  <= out_pixel;
            end else if (pend_clr) begin
                pend_valid <= 1'b0;
            end
        end
    end

    // ---- counters ---------------------------------------------------------
    reg [15:0] coef_cnt;
    reg [15:0] pix_cnt;
    reg [3:0]             wait_cnt;
    reg                   tx_sent;

    localparam integer PIPE_DEPTH = 6;   // 4 core stages + pend_valid reg + margin

    assign busy_led = (state != S_DONE);

    always @(posedge clk) begin
        if (rst) begin
            state     <= S_COEF;
            coef_we   <= 1'b0;
            coef_addr <= 0;
            coef_din  <= 8'd0;
            in_valid  <= 1'b0;
            in_pixel  <= 8'd0;
            tx_start  <= 1'b0;
            tx_data   <= 8'd0;
            pend_clr  <= 1'b0;
            coef_cnt  <= 0;
            pix_cnt   <= 0;
            wait_cnt  <= 4'd0;
            tx_sent   <= 1'b0;
            frame_rst <= 1'b0;
            done_led  <= 1'b0;
        end else begin
            // default strobes
            coef_we   <= 1'b0;
            in_valid  <= 1'b0;
            tx_start  <= 1'b0;
            pend_clr  <= 1'b0;
            frame_rst <= 1'b0;

            case (state)
                // ---- load N*N kernel coefficients ------------------------
                S_COEF: begin
                    if (rx_valid) begin
                        coef_we   <= 1'b1;
                        coef_addr <= coef_cnt[3:0];
                        coef_din  <= rx_data;
                        if (coef_cnt == TAPS-1) begin
                            coef_cnt <= 0;
                            state    <= S_RXPIX;
                        end else begin
                            coef_cnt <= coef_cnt + 1'b1;
                        end
                    end
                end

                // ---- wait for the next pixel byte ------------------------
                S_RXPIX: begin
                    if (rx_valid) begin
                        in_pixel <= rx_data;
                        state    <= S_FEED;
                    end
                end

                // ---- present it to the core for exactly one cycle --------
                S_FEED: begin
                    in_valid <= 1'b1;
                    wait_cnt <= 4'd0;
                    pix_cnt  <= pix_cnt + 1'b1;
                    state    <= S_WAIT;
                end

                // ---- let the pipeline settle -----------------------------
                S_WAIT: begin
                    if (wait_cnt == PIPE_DEPTH) begin
                        if (pend_valid)          state <= S_TX_HI;
                        else if (pix_cnt == NPIX) state <= S_DONE;
                        else                      state <= S_RXPIX;
                    end else begin
                        wait_cnt <= wait_cnt + 1'b1;
                    end
                end

                // ---- send the 16-bit result, big-endian ------------------
                // NOTE: uart_tx clears tx_busy on the SAME edge it pulses
                // tx_done, so "!tx_busy" cannot be used to decide whether we
                // still owe a byte - it would re-arm and resend forever.
                // tx_sent records that this byte has been handed over.
                S_TX_HI: begin
                    if (!tx_sent) begin
                        if (!tx_busy) begin
                            tx_data  <= pend_data[15:8];
                            tx_start <= 1'b1;
                            tx_sent  <= 1'b1;
                        end
                    end else if (tx_done) begin
                        tx_sent <= 1'b0;
                        state   <= S_TX_LO;
                    end
                end

                S_TX_LO: begin
                    if (!tx_sent) begin
                        if (!tx_busy) begin
                            tx_data  <= pend_data[7:0];
                            tx_start <= 1'b1;
                            tx_sent  <= 1'b1;
                        end
                    end else if (tx_done) begin
                        tx_sent  <= 1'b0;
                        pend_clr <= 1'b1;
                        if (pix_cnt == NPIX) state <= S_DONE;
                        else                 state <= S_RXPIX;
                    end
                end

                // ---- frame complete: signal done, reset core, await next kernel --
                S_DONE: begin
                    done_led  <= 1'b1;
                    frame_rst <= 1'b1;    // reset core counters for next pass
                    pix_cnt   <= 16'd0;   // ready for next image stream
                    state     <= S_COEF;  // accept another kernel immediately
                end

                default: state <= S_COEF;
            endcase
        end
    end
endmodule

`default_nettype wire
