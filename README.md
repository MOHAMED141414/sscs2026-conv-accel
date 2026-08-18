# FPGA-Based Edge-AI Vision Accelerator

**3x3 CNN convolution engine — IEEE SSCS Egypt Chapter, 2026 Student Design Competition**

A streaming convolution accelerator for the Xilinx Virtex-5 XC5VLX50T (Digilent Genesys), sustaining **one output pixel per clock cycle** with **zero block RAM**, verified bit-exact against a Python golden model and closed at **167.0 MHz** against a 100 MHz target. Supports **multiple kernels** sequentially without hardware reset.

---

## Results at a glance

| Metric | Value |
|---|---|
| Slice LUTs | 317 |
| Slice Registers | 275 |
| DSP48E | 9 |
| **Block RAM** | **0** |
| Occupied Slices | 132 |
| Fmax (post-route) | 167.0 MHz |
| Timing | All constraints met, timing score 0 |
| Power (total) | 476 mW (21 mW dynamic / 455 mW static leakage) |
| Throughput | 0.8755 out px/cycle sustained, 1.0 peak |
| Latency | 70 cycles to first output, 1028 cycles per 32x32 frame |
| Verification | 80 / 80 cases bit-exact (72 core + 6 system + 2 multi-kernel) |
| **Figure of Merit** | **2.398 x 10^-3** |

### Bonus features achieved

- **One output pixel per cycle** — pipelined architecture, confirmed by organizer as meeting the bonus
- **Support for multiple kernels** — FSM loops S_DONE -> S_COEF; verified with back-to-back Sobel X + Laplacian, no hardware reset
- **ReLU activation** — single-cycle clamp after saturation
- **Programmable coefficients** — 9 x int8 register file loaded over UART (required spec)
- Board demonstration — bitstream ready, pending hardware access
- Edge-detection demo — host driver supports --image-file

---

## Architecture

Line-buffer sliding-window convolver. Pixels arrive one per cycle on a valid-qualified stream; two 32-deep shift registers delay the stream by one and two image rows so that the newest pixel plus the two delayed taps form the rightmost column of a 3x3 register window.

| Stage | Function | Output |
|---|---|---|
| S0 | Line buffers + 3x3 window registers | 9 window pixels |
| S1 | Nine parallel 9x8 signed multiplies | 9 products (17-bit) |
| S2 | Three row sums (3-term adders) | 3 partial sums (22-bit) |
| S3 | Final sum, saturation, optional ReLU | 1 output pixel (16-bit) |

**Zero BRAM by construction.** The line buffers are flat shift registers, which XST infers as sixteen 30-bit SRL primitives occupying 17 LUTs. The competition Figure of Merit charges 100 penalty units per BRAM, so keeping them in LUT fabric matters more than the 512 bits suggest.

**Stall-tolerant pipeline.** Every state element is gated on in_valid, so gaps in the input stream are harmless. The host wrapper therefore advances the pixel stream at UART pace rather than buffering 900 results — one 16-bit pending register replaces what would otherwise be a 14.4 kbit output FIFO.

**Multi-kernel operation.** After completing a frame, the FSM pulses frame_rst (which resets the core's position counters and valid pipeline without clearing line buffers or coefficients), zeroes pix_cnt, and transitions back to S_COEF. The host can immediately send a new kernel and image without pressing the reset button.

### Fixed-point arithmetic

Input pixels are 8-bit unsigned, zero-extended to 9-bit signed; coefficients are 8-bit signed; products are exactly 17 bits. Worst-case accumulator excursion:

| Kernel | Max positive | Max negative | Bits needed |
|---|---|---|---|
| 3x3 | +291,465 | -293,760 | 20 |
| 5x5 | +809,625 | -816,000 | 21 |
| 7x7 | +1,586,865 | -1,599,360 | 22 |

A 22-bit accumulator is implemented. Because the accumulator range exceeds the 16-bit output range by roughly 9x, **saturation is mandatory, not optional** — results clamp to [-32768, +32767] rather than wrapping. ReLU, when enabled, is applied after saturation.

---

## Design-space exploration: DSP48E vs LUT multipliers

The Figure of Merit charges 50 penalty units per DSP:

    FOM = Throughput / [ Power x (LUTs + 50*DSPs + 100*BRAMs) ]

With nine DSP48E blocks contributing 450 units — 60% of the resource denominator — the natural hypothesis is that LUT multipliers would score better. Two complete builds were synthesised, placed and routed to test this.

| | Build A — DSP48E | Build B — LUT multipliers |
|---|---|---|
| Slice LUTs | **317** | 1,318 |
| Slice Registers | **275** | 581 |
| DSP48E | 9 | **0** |
| Block RAM | **0** | **0** |
| Resource cost | **767** | 1,318 |
| Fmax | **167.0 MHz** | 132.8 MHz |
| **FOM** | **2.398 x 10^-3** | 1.395 x 10^-3 |

**The hypothesis was wrong.** Each 9x8 signed multiplier costs about 113 LUTs in Virtex-5 fabric, so removing the DSPs saved 450 penalty units but added 1,013 LUTs — a net 563 units worse, plus a 24% loss of maximum frequency. Build A is the submitted design.

---

## Verification

| Level | Cases | Coverage | Result |
|---|---|---|---|
| Core (unit) | 72 | 6 images x 6 kernels x ReLU on/off, 900 px each | 72/72 bit-exact |
| System (UART) | 6 | Full protocol incl. coefficient load and readback | 900/900 each |
| Multi-kernel | 2 | Sobel X then Laplacian, back-to-back, no reset | Both passes 900/900 |
| Host driver | 8 | Protocol sequencing with no hardware (dry run) | All pass |

20 of the 72 core cases drive the accumulator into saturation deliberately. The identity kernel is asserted to reproduce the image interior exactly, which independently validates window alignment.

### Defects found and fixed

**Window-valid pipeline misalignment.** The window registers and position counters update on the same clock edge, so the valid flag led the data by one cycle. Fixed with a registered win_valid_q stage.

**UART transmit handshake race.** uart_tx clears tx_busy on the same edge it pulses tx_done, so testing !tx_busy re-armed the transmitter indefinitely. Fixed with an explicit tx_sent flag.

---

## Repository layout

    rtl/                 conv_accel.v       streaming 3x3 convolution core
                         conv_top.v         top level: control FSM + host interface
                         uart_rx.v          8N1 UART receiver
                         uart_tx.v          8N1 UART transmitter
    tb/                  tb_conv_accel.v    core unit testbench (self-checking)
                         tb_conv_top.v      system testbench over the UART protocol
                         tb_multi_kernel.v  multi-kernel bonus testbench
    golden/              conv_golden.py     golden model + test-vector generator
    host/                host_driver.py     serial driver, with --dry-run mode
    sim/                 run_regression.sh  full 72-case sweep
    fpga/                conv_top.ucf       pin and timing constraints
                         fom.py             Figure of Merit calculator
                         reports_dsp/       ISE reports, build A (submitted)
                         reports_lut/       ISE reports, build B (comparison)
    docs/                report and presentation
    docs/figures/        block diagram, FSM diagram, waveform captures

---

## Reproducing the results

Requires python3, numpy, and iverilog.

    # generate test vectors
    python3 golden/conv_golden.py

    # full 72-case core regression
    bash sim/run_regression.sh

    # system-level test
    iverilog -g2012 -o build/top.vvp rtl/conv_accel.v rtl/uart_rx.v \
             rtl/uart_tx.v rtl/conv_top.v tb/tb_conv_top.v
    vvp build/top.vvp +IMG=vectors/img_ramp.hex \
        +KER=vectors/kernel_sobel_x.hex \
        +EXP=vectors/exp_ramp__sobel_x.hex +RELU=0

    # multi-kernel bonus test
    iverilog -g2012 -o build/multi.vvp rtl/conv_accel.v rtl/uart_rx.v \
             rtl/uart_tx.v rtl/conv_top.v tb/tb_multi_kernel.v
    vvp build/multi.vvp

    # host driver (no hardware needed)
    python3 host/host_driver.py --dry-run --kernel sobel_x --image ramp

    # Figure of Merit
    python3 fpga/fom.py --luts 317 --ffs 275 --dsps 9 --brams 0 \
            --power 0.476 --fmax 167.0

### On hardware

    pip install pyserial
    python3 host/host_driver.py --port /dev/ttyUSB0 --kernel sobel_x --image ramp
    # second kernel immediately after (no reset needed)
    python3 host/host_driver.py --port /dev/ttyUSB0 --kernel laplacian --image ramp

---

## Status

### Complete

- [x] Golden model with derived bit-width analysis
- [x] RTL: streaming core, control FSM, UART receiver and transmitter
- [x] Multi-kernel support (FSM loops S_DONE -> S_COEF with frame_rst)
- [x] Core regression — 72/72 bit-exact
- [x] System verification — 900/900
- [x] Multi-kernel verification — 2 passes back-to-back, both 900/900
- [x] Host-side driver with hardware-free dry-run mode
- [x] Synthesis, place and route, timing closure (score 0)
- [x] Power analysis (XPower)
- [x] DSP48E vs LUT-multiplier comparison — both builds fully implemented
- [x] Figure of Merit: 2.398 x 10^-3
- [x] Bitstream generated
- [x] Block diagram and FSM state diagram
- [x] Simulation waveform captures
- [x] Progress report (PDF)
- [x] Presentation deck (12 slides)

### Remaining

- [ ] Board demonstration (optional bonus) — bitstream ready, pending hardware access
- [ ] Edge-detection demo on real imagery (optional bonus)
- [ ] Copy updated ISE reports to fpga/reports_dsp/
- [ ] Final report assembly
- [ ] Verify uart_rx pin assignment (AB32, inferred; unconfirmed)

**Deadline:** 15 September 2026

---

## License

Submitted as a student competition entry. Contact the author before reuse.
