//=============================================================================
// conv_top.v  -  SAME-padding top level, TRUE zero-gap (1-output-per-cycle bonus)
// IEEE SSCS Egypt Chapter 2026 Student Design Competition
//
// Uses conv_accel_same, which handles all zero-padding internally (top
// padding via line-buffer reset state, left padding via window-column
// masking) -- no padding pixels are fed over the wire at all. The host
// sends exactly NPIX real pixel bytes; the core produces exactly NPIX
// results with zero gaps between them (verified at the core level: 0
// cycles where out_valid drops for >=1 cycle during the entire stream).
//
// HOST PROTOCOL:
//   1. Send 9 kernel bytes
//   2. Send NPIX pixel bytes
//   3. Receive NPIX x 2 result bytes (streamed as they become ready,
//      buffered through a small FIFO to decouple core rate from UART rate)
//=============================================================================
`timescale 1ns / 1ps
`default_nettype none

module conv_top #(
    parameter integer IMG_W        = 32,
    parameter integer IMG_H        = 32,
    parameter integer N            = 3,
    parameter integer CLKS_PER_BIT = 868
)(
    input  wire       clk,
    input  wire       rst,
    input  wire       relu_en,
    input  wire       uart_rx,
    output wire       uart_tx,
    output wire       busy_led,
    output reg        done_led
);
    localparam integer TAPS = N * N;
    localparam integer NPIX = IMG_W * IMG_H;

    localparam S_COEF   = 2'd0,
               S_STREAM = 2'd1,
               S_FLUSH  = 2'd2,
               S_DONE   = 2'd3;

    reg [1:0] state;

    // ---- UART ---------------------------------------------------------------
    wire       rx_valid;
    wire [7:0] rx_data;
    reg        tx_start;
    reg  [7:0] tx_data_r;
    wire       tx_done, tx_busy;

    uart_rx #(.CLKS_PER_BIT(CLKS_PER_BIT)) u_rx (
        .clk(clk), .rst(rst), .rx(uart_rx),
        .rx_valid(rx_valid), .rx_data(rx_data));
    uart_tx #(.CLKS_PER_BIT(CLKS_PER_BIT)) u_tx (
        .clk(clk), .rst(rst),
        .tx_start(tx_start), .tx_data(tx_data_r),
        .tx(uart_tx), .tx_busy(tx_busy), .tx_done(tx_done));

    // ---- core (native image dims -- no padded size needed) -------------------
    reg                 coef_we;
    reg  [3:0]          coef_addr;
    reg  signed [7:0]   coef_din;
    reg                 in_valid;
    reg  [7:0]          in_pixel;
    wire                out_valid;
    wire signed [15:0]  out_pixel;
    reg                 frame_rst;

    conv_accel_same #(.IMG_W(IMG_W), .IMG_H(IMG_H), .N(N)) u_core (
        .clk(clk), .rst(rst),
        .coef_we(coef_we), .coef_addr(coef_addr), .coef_din(coef_din),
        .relu_en(relu_en), .frame_rst(frame_rst),
        .in_valid(in_valid), .in_pixel(in_pixel),
        .out_valid(out_valid), .out_pixel(out_pixel));

    // ---- output FIFO (depth 32 -- decouples core rate from UART rate) --------
    localparam FD = 32;
    reg signed [15:0] fifo [0:FD-1];
    reg [5:0] f_wr, f_cnt;
    reg [4:0] f_rd;
    wire f_empty = (f_cnt == 0);
    wire f_full  = (f_cnt == FD);

    always @(posedge clk) begin
        if (rst || frame_rst) begin
            f_wr <= 0; f_cnt <= 0;
        end else if (out_valid && !f_full) begin
            fifo[f_wr[4:0]] <= out_pixel;
            f_wr  <= f_wr + 1'b1;
            f_cnt <= f_cnt + 1'b1;
        end
    end

    // ---- TX state machine (drains FIFO over UART, 2 bytes/result) -----------
    reg        tx_lo_phase;
    reg        tx_sent;
    reg [15:0] tx_word;
    reg [15:0] tx_out_cnt;

    always @(posedge clk) begin
        if (rst || frame_rst) begin
            tx_lo_phase <= 1'b0; tx_sent <= 1'b0; tx_out_cnt <= 0;
            tx_start <= 1'b0; tx_data_r <= 8'd0; tx_word <= 16'd0; f_rd <= 0;
        end else begin
            tx_start <= 1'b0;
            if (!tx_lo_phase) begin
                if (!f_empty && tx_out_cnt < NPIX && !tx_sent) begin
                    tx_word   <= fifo[f_rd];
                    tx_data_r <= fifo[f_rd][15:8];
                    tx_start  <= 1'b1;
                    tx_sent   <= 1'b1;
                end else if (tx_done && tx_sent) begin
                    tx_lo_phase <= 1'b1;
                    tx_sent     <= 1'b0;
                end
            end else begin
                if (!tx_sent) begin
                    tx_data_r <= tx_word[7:0];
                    tx_start  <= 1'b1;
                    tx_sent   <= 1'b1;
                end else if (tx_done) begin
                    tx_lo_phase <= 1'b0;
                    tx_sent     <= 1'b0;
                    tx_out_cnt  <= tx_out_cnt + 1'b1;
                    f_rd        <= f_rd + 1'b1;
                    f_cnt       <= f_cnt - 1'b1;
                end
            end
        end
    end

    // ---- main FSM: simplified -- no padding states needed --------------------
    reg [15:0] coef_cnt, pix_cnt;
    assign busy_led = (state != S_DONE);

    always @(posedge clk) begin
        if (rst) begin
            state <= S_COEF; coef_we <= 0; coef_addr <= 0; coef_din <= 0;
            in_valid <= 0; in_pixel <= 0; frame_rst <= 0;
            coef_cnt <= 0; pix_cnt <= 0; done_led <= 0;
        end else begin
            coef_we   <= 1'b0;
            in_valid  <= 1'b0;
            frame_rst <= 1'b0;

            case (state)
                S_COEF: if (rx_valid) begin
                    coef_we <= 1'b1; coef_addr <= coef_cnt[3:0]; coef_din <= rx_data;
                    if (coef_cnt == TAPS-1) begin
                        coef_cnt <= 0; state <= S_STREAM;
                    end else
                        coef_cnt <= coef_cnt + 1'b1;
                end

                S_STREAM: if (rx_valid) begin
                    in_valid <= 1'b1; in_pixel <= rx_data;
                    pix_cnt  <= pix_cnt + 1'b1;
                    if (pix_cnt == NPIX-1) state <= S_FLUSH;
                end

                S_FLUSH: if (tx_out_cnt == NPIX) state <= S_DONE;

                S_DONE: begin
                    done_led  <= 1'b1;
                    frame_rst <= 1'b1;
                    pix_cnt   <= 0;
                    state     <= S_COEF;
                end
            endcase
        end
    end
endmodule
`default_nettype wire
