# FPGA-Based Edge-AI Vision Accelerator

**3×3 CNN convolution engine — IEEE SSCS Egypt Chapter, 2026 Student Design Competition**

A streaming convolution accelerator for the Xilinx Virtex-5 XC5VLX50T (Digilent Genesys),
sustaining **one output pixel per clock cycle** with **zero block RAM**, verified bit-exact
against a Python golden model and closed at **174.4 MHz** against a 100 MHz target.

---

## Results at a glance

| Metric | Value |
|---|---|
| Slice LUTs | 299 |
| Slice Registers | 274 |
| DSP48E | 9 |
| **Block RAM** | **0** |
| Occupied Slices | 123 |
| F<sub>max</sub> (post-route) | 174.4 MHz |
| Timing | All constraints met, timing score 0 |
| Power (total) | 476 mW (21 mW dynamic / 455 mW static leakage) |
| Throughput | 0.8755 out px/cycle sustained · 1.0 peak |
| Latency | 70 cycles to first output · 1,028 cycles per 32×32 frame |
| Verification | 78 / 78 cases bit-exact |
| **Figure of Merit** | **2.456 × 10⁻³** |

All figures are post-place-and-route from ISE 14.7 with all seven I/O pins constrained.
Power is from XPower Analyzer, vector-less activity propagation, 50 °C ambient, typical process.

---

## Architecture

Line-buffer sliding-window convolver. Pixels arrive one per cycle on a valid-qualified
stream; two 32-deep shift registers delay the stream by one and two image rows so that the
newest pixel plus the two delayed taps form the rightmost column of a 3×3 register window.

| Stage | Function | Output |
|---|---|---|
| S0 | Line buffers + 3×3 window registers | 9 window pixels |
| S1 | Nine parallel 9×8 signed multiplies | 9 products (17-bit) |
| S2 | Three row sums (3-term adders) | 3 partial sums (22-bit) |
| S3 | Final sum, saturation, optional ReLU | 1 output pixel (16-bit) |

**Zero BRAM by construction.** The line buffers are flat shift registers, which XST infers as
sixteen 30-bit SRL primitives occupying 17 LUTs. The competition Figure of Merit charges 100
penalty units per BRAM, so keeping them in LUT fabric matters more than the 512 bits suggest.

**Stall-tolerant pipeline.** Every state element is gated on `in_valid`, so gaps in the input
stream are harmless. The host wrapper therefore advances the pixel stream at UART pace rather
than buffering 900 results — one 16-bit pending register replaces what would otherwise be a
14.4 kbit output FIFO.

### Fixed-point arithmetic

Input pixels are 8-bit unsigned, zero-extended to 9-bit signed; coefficients are 8-bit signed;
products are exactly 17 bits. Worst-case accumulator excursion:

| Kernel | Max positive | Max negative | Bits needed |
|---|---|---|---|
| 3×3 | +291,465 | −293,760 | 20 |
| 5×5 | +809,625 | −816,000 | 21 |
| 7×7 | +1,586,865 | −1,599,360 | 22 |

A 22-bit accumulator is implemented. Because the accumulator range exceeds the 16-bit output
range by roughly 9×, **saturation is mandatory, not optional** — results clamp to
[−32,768, +32,767] rather than wrapping. ReLU, when enabled, is applied after saturation.

---

## Design-space exploration: DSP48E vs LUT multipliers

The Figure of Merit charges 50 penalty units per DSP:

```
FOM = Throughput / [ Power × (LUTs + 50×DSPs + 100×BRAMs) ]
```

With nine DSP48E blocks contributing 450 units — 60% of the resource denominator — the natural
hypothesis is that LUT multipliers would score better. Two complete builds were synthesised,
placed and routed to test this.

| | Build A — DSP48E | Build B — LUT multipliers |
|---|---|---|
| Slice LUTs | **299** | 1,318 |
| Slice Registers | **274** | 581 |
| DSP48E | 9 | **0** |
| Block RAM | **0** | **0** |
| Resource cost | **749** | 1,318 |
| F<sub>max</sub> | **174.4 MHz** | 132.8 MHz |
| **FOM** | **2.456 × 10⁻³** | 1.395 × 10⁻³ |

**The hypothesis was wrong.** Each 9×8 signed multiplier costs ≈113 LUTs in Virtex-5 fabric, so
removing the DSPs saved 450 penalty units but added 1,013 LUTs — a net 563 units worse, plus a
24% loss of maximum frequency. Build A is the submitted design.

---

## Verification

| Level | Cases | Coverage | Result |
|---|---|---|---|
| Core (unit) | 72 | 6 images × 6 kernels × ReLU on/off, 900 px each | 72/72 bit-exact |
| System (UART) | 6 | Full protocol incl. coefficient load and readback | 900/900 each |
| Host driver | 8 | Protocol sequencing with no hardware (dry run) | All pass |

20 of the 72 core cases drive the accumulator into saturation deliberately, using all-+127 and
all-−128 kernels against maximum-intensity images. The identity kernel is asserted to reproduce
the image interior exactly, which independently validates window alignment.

### Defects found and fixed

**Window-valid pipeline misalignment.** The window registers and position counters update on the
same clock edge, so at the edge admitting pixel (r, c) the product stage still reads the window
ending at (r, c−1). The valid flag led the data by one cycle and every output shifted by one
position. Fixed with a registered `win_valid_q` stage.

**UART transmit handshake race.** `uart_tx` clears `tx_busy` on the same edge it pulses
`tx_done`, so deciding whether a byte was still owed by testing `!tx_busy` re-armed the
transmitter on the completion cycle — the FSM resent the same byte indefinitely. Fixed with an
explicit `tx_sent` flag.

---

## Repository layout

```
rtl/                 conv_accel.v   streaming 3×3 convolution core
                     conv_top.v     top level: control FSM + host interface
                     uart_rx.v      8N1 UART receiver
                     uart_tx.v      8N1 UART transmitter
tb/                  tb_conv_accel.v   core unit testbench (self-checking)
                     tb_conv_top.v     system testbench over the UART protocol
golden/              conv_golden.py    golden model + test-vector generator
host/                host_driver.py    serial driver, with --dry-run mode
sim/                 run_regression.sh full 72-case sweep
fpga/                conv_top.ucf      pin and timing constraints
                     fom.py            Figure of Merit calculator
                     reports_dsp/      ISE reports, build A (submitted)
                     reports_lut/      ISE reports, build B (comparison)
docs/                report and presentation
docs/figures/        block diagram, FSM diagram, waveform captures
```

---

## Reproducing the results

Requires `python3`, `numpy`, and `iverilog`.

```bash
# generate test vectors and print the bit-width analysis
python3 golden/conv_golden.py

# full 72-case core regression
bash sim/run_regression.sh

# system-level test over the UART protocol
iverilog -g2012 -o build/top.vvp rtl/conv_accel.v rtl/uart_rx.v \
         rtl/uart_tx.v rtl/conv_top.v tb/tb_conv_top.v
vvp build/top.vvp +IMG=vectors/img_ramp.hex \
    +KER=vectors/kernel_sobel_x.hex \
    +EXP=vectors/exp_ramp__sobel_x.hex +RELU=0

# host driver, no hardware needed
python3 host/host_driver.py --dry-run --kernel sobel_x --image ramp

# Figure of Merit
python3 fpga/fom.py --luts 299 --ffs 274 --dsps 9 --brams 0 \
        --power 0.476 --fmax 174.4
```

### On hardware

```bash
pip install pyserial
python3 host/host_driver.py --port /dev/ttyUSB0 --kernel sobel_x --image ramp
```

The `relu_en` switch must match the `--relu` flag.

---

## Host protocol

Request–response over UART, 115200 baud, 8N1. No flow-control lines needed.

1. Host sends 9 kernel coefficient bytes (int8, row-major)
2. Host sends pixel bytes one at a time
3. For each pixel completing a window (row ≥ 2 and col ≥ 2), the board replies with 2 bytes
   (int16, big-endian) before the host sends the next pixel

---

## Toolchain notes

Built with Xilinx ISE 14.7 (XST, MAP, PAR, TRCE, XPower Analyzer). The core was first written
generically for N×N using arrays and generate loops, which Icarus Verilog accepts but XST 14.7
does not — it rejects `localparam` inside generate blocks, array elements in implicit sensitivity
lists (`Xst:902`), and for-loop bounds over arrays inside always blocks (`Xst:2634`) even when
static. The datapath was rewritten with flat vectors and discrete registers; arithmetic and
pipeline depth are unchanged and the full regression passes identically before and after.

N is fixed at 3 in the synthesised build. Kernel *coefficients* remain runtime-programmable, as
the specification requires. The generic N×N version is kept in `docs/attic/`.

---

## Status

### Complete

- [x] Golden model with derived bit-width analysis
- [x] RTL: streaming core, control FSM, UART receiver and transmitter
- [x] Core regression — 72/72 bit-exact
- [x] System verification over the UART protocol — 900/900
- [x] Host-side driver with hardware-free dry-run mode
- [x] Synthesis, place and route, timing closure (score 0)
- [x] Power analysis (XPower)
- [x] DSP48E vs LUT-multiplier comparison — both builds fully implemented
- [x] Figure of Merit
- [x] Bitstream generated
- [x] Block diagram and FSM state diagram
- [x] Simulation waveform captures
- [x] Progress report (PDF)
- [x] Presentation deck

### Remaining

- [ ] **Board demonstration** *(optional bonus)* — bitstream ready, pending hardware access
- [ ] **Edge-detection demo on real imagery** *(optional bonus)* — host driver supports it via `--image-file`
- [ ] Final report assembly — merge progress report with figures and any demo results
- [ ] Verify the `uart_rx` pin assignment (currently AB32, inferred as the differential
      partner of `uart_tx` on AC32; unconfirmed against the board wiring)

**Deadline:** 15 September 2026

---

## License

Submitted as a student competition entry. Contact the author before reuse.
