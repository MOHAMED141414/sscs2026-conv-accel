# FPGA-Based Edge-AI Vision Accelerator

**3x3 CNN convolution engine — IEEE SSCS Egypt Chapter, 2026 Student Design Competition**

A streaming convolution accelerator for the Xilinx Virtex-5 XC5VLX50T (Digilent Genesys). Two builds are submitted: a lean **VALID-border** design (best Figure of Merit) and a **SAME-padding, true zero-gap** design that satisfies the organizer's strict one-output-per-cycle bonus. Both are fully verified, synthesised, and timing-closed.

---

## Two builds, one honest trade-off

The competition clarified that the one-output-per-cycle bonus requires `out_valid` to never drop for two or more cycles during active processing — "even because of row or window boundaries." The VALID design does not meet that bar (it skips output for incomplete edge windows). The SAME design was built specifically to clear it, with the gap-free behavior *proven*, not asserted, at the core level.

| Metric | VALID (primary) | SAME (zero-gap bonus) |
|---|---|---|
| Slice LUTs | 317 | 435 |
| Slice Registers | 275 | 325 |
| DSP48E | 9 | 9 |
| Block RAM | 0 | 0 |
| Fmax (post-route) | 167.0 MHz | 165.7 MHz |
| Timing score | 0 | 0 |
| Sustained throughput | 0.8755 out px/cycle | **1.0000 out px/cycle** |
| Frame cycles (32x32) | 1028 | 1024 |
| Verification | 78/78 bit-exact | 1024/1024 bit-exact, proven zero-gap |
| **Figure of Merit** | **2.398 x 10^-3** | 2.374 x 10^-3 |

The SAME build's FoM is 1.0% lower — the masking logic and output FIFO cost 118 more LUTs than the throughput gain buys back. This is a genuine engineering trade-off, not a strict win, and it's reported as such: VALID is the primary FoM entry, SAME is submitted specifically to satisfy the bonus with real, measured gap-free operation.

---

## Architecture (shared by both builds)

Line-buffer sliding-window convolver. Pixels arrive one per cycle on a valid-qualified stream; two IMG_W-deep shift registers delay the stream by one and two image rows so that the newest pixel plus the two delayed taps form the rightmost column of a 3x3 register window.

| Stage | Function | Output |
|---|---|---|
| S0 | Line buffers + 3x3 window registers | 9 window pixels |
| S1 | Nine parallel 9x8 signed multiplies | 9 products (17-bit) |
| S2 | Three row sums (3-term adders) | 3 partial sums (22-bit) |
| S3 | Final sum, saturation, optional ReLU | 1 output pixel (16-bit) |

**Zero BRAM by construction.** The line buffers are flat shift registers, inferred by XST as SRL primitives in LUT fabric. The competition Figure of Merit charges 100 penalty units per BRAM, so this matters more than the raw bit count suggests.

**Stall-tolerant pipeline.** Every state element is gated on `in_valid`, so gaps in the input stream are harmless in both builds.

---

## How the SAME build achieves TRUE zero-gap operation

The first SAME attempt injected literal zero-padding pixels between image rows to zero-pad the convolution mathematically. It worked numerically, but each injected pixel cost one real clock cycle — producing a 2-cycle stall at every row boundary. That is exactly the failure mode the organizer called out. Measured directly: 31 violations (one per row transition), sustained throughput ~94.3%, not the required 100%.

**The fix removes the padding cycles entirely**, using two separate mechanisms depending on which edge of the image is involved:

**Top padding is free.** The line buffers (`lb0`, `lb1`) are IMG_W-deep shift registers, reset to zero. `lb0_out` ("one row back") only starts returning real data after IMG_W valid pushes — before that it outputs the reset zero, which *is* correct zero-padding for row -1. `lb1_out` ("two rows back") stays zero through both row 0 and row 1 for the same reason. No extra pixels need to be fed; the delay-line's natural fill time provides the padding.

**Left padding needs masking, not injection.** The window shift registers (`w00..w22`) are a pure shift chain with no per-row reset, so at the start of a new row they still hold the *previous* row's trailing pixels — wraparound contamination, not zero. Rather than injecting pixels to flush this out, the window's two oldest columns are masked to zero combinationally whenever fewer than 2 (or 1) real pixels of the current row have been seen. A saturating counter (`rundist`, capped at 3) tracks "consecutive same-row pushes" specifically to avoid the wraparound-vs-fresh-start ambiguity: the ordinary column counter wraps to 0 at the end of every row, which is indistinguishable from "start of row" unless tracked separately.

Verified directly: feeding conv_accel_same continuously with only the 1024 real pixels (no padding pixels of any kind) produces 1024/1024 bit-exact outputs with **0 cycles of any out_valid gap**, checked by an explicit cycle-by-cycle monitor — not inferred from a smaller number of observed violations.

### Real bugs hit and fixed along the way

- **Verilog sign-mixing in the mask ternary.** `mask0 ? 0 : $signed(...)` silently produced an unsigned expression, corrupting the multiply stage. Fixed with an explicit signed-zero constant.
- **`dist` is a reserved SystemVerilog keyword** — caused a cascade of confusing syntax errors in Icarus. Renamed to `rundist`.
- **Column-counter wraparound aliasing.** The natural column counter reads identically at "just wrapped past the last pixel of a full row" and "genuinely at the first pixel of a new row," causing false masking on the last pixel of every row. Fixed with the saturating `rundist` counter described above.
- **Multi-driver register, tolerated by simulation, rejected by synthesis.** `f_cnt` (FIFO occupancy) was incremented in one `always` block and decremented in another. Icarus simulated this via scheduling-order luck; XST correctly refused it (`ERROR:Xst:528 - Multi-source`). Fixed by consolidating both into one block driven by `push`/`pop` wires, handling the simultaneous push+pop case explicitly.
- **Declare-before-use ordering.** XST's HDL compiler is stricter than Icarus about a wire referencing registers declared later in the file. Reordered declarations to match.
- **UART pin mapping on the physical board.** The Genesys RS-232 port did not match the assumed AF19/AG16 pinout from prior notes; resolved by consulting the board schematic directly (ST3232 T1IN/R1OUT pins) and confirmed against the pad report.

---

## Verification summary

| Level | Cases | Coverage | Result |
|---|---|---|---|
| VALID core (unit) | 72 | 6 images x 6 kernels x ReLU on/off | 72/72 bit-exact |
| VALID system (UART) | 6 | Full protocol incl. coefficient load | 900/900 each |
| VALID multi-kernel | 2 | Sobel X then Laplacian, no reset | Both 900/900 |
| SAME core, continuous feed | 1024 | Real pixels only, no injected padding | 1024/1024 bit-exact, 0-cycle max gap |
| SAME system (UART) | 1024 | Request-response protocol | 1024/1024 bit-exact, 0 violations >=2 cycles |
| SAME saturation | 1024 | All-255 image, saturating kernel | 1024/1024 bit-exact incl. masked edges |
| SAME multi-kernel (UART) | 2x64 | Sobel X then Laplacian, no reset | Both passes bit-exact |

---

## Repository layout

    rtl/                 conv_accel.v        VALID-border core (submitted primary)
                         conv_top.v          VALID-border top level
                         conv_accel_same.v   SAME-padding core, true zero-gap
                         conv_top_same.v     SAME-padding top level
                         uart_rx.v, uart_tx.v
    tb/                  tb_conv_accel.v        VALID core regression (72 cases)
                         tb_conv_top.v          VALID system test
                         tb_multi_kernel.v      VALID multi-kernel test
                         tb_same_core_check.v   SAME core, continuous-feed gap proof
                         tb_conv_same.v         SAME system test (1024 px)
                         tb_same_multi.v        SAME multi-kernel, core level
                         tb_same_uart_multi8.v  SAME multi-kernel, over UART
    golden/              conv_golden.py      golden model + VALID vectors
    host/                host_driver.py      serial driver, --dry-run mode
    sim/                 run_regression.sh   VALID 72-case sweep
    fpga/                conv_top.ucf        pin and timing constraints (shared)
                         fom.py              Figure of Merit calculator
                         reports_dsp/        ISE reports, VALID + DSP48E build
                         reports_lut/        ISE reports, VALID + LUT-multiplier build
                         reports_same/       ISE reports, SAME zero-gap build
    vectors/             VALID golden vectors
    vectors_same_hw/     SAME golden vectors (asymmetric top+left zero padding)
    docs/                report and presentation
    docs/figures/        block diagram, FSM diagram, waveform captures

---

## Reproducing the results

Requires `python3`, `numpy`, and `iverilog`.

    # VALID build: full 72-case core regression
    bash sim/run_regression.sh

    # SAME build: core-level zero-gap proof (no UART, no injected padding)
    iverilog -g2012 -o build/samecore.vvp rtl/conv_accel_same.v tb/tb_same_core_check.v
    vvp build/samecore.vvp
    # expect: PASS 1024/1024 bit-exact, max gap=0 cycles, gap>=2 violations=0

    # SAME build: full system test over UART
    iverilog -g2012 -o build/samesys.vvp rtl/conv_accel_same.v rtl/uart_rx.v \
             rtl/uart_tx.v rtl/conv_top_same.v tb/tb_conv_same.v
    vvp build/samesys.vvp

    # SAME build: multi-kernel, no hardware reset between passes
    iverilog -g2012 -o build/multi8.vvp rtl/conv_accel_same.v rtl/uart_rx.v \
             rtl/uart_tx.v rtl/conv_top_same.v tb/tb_same_uart_multi8.v
    vvp build/multi8.vvp

    # Figure of Merit, either build
    python3 fpga/fom.py --luts 317 --ffs 275 --dsps 9 --brams 0 --power 0.476 --fmax 167.0
    python3 fpga/fom.py --luts 435 --ffs 325 --dsps 9 --brams 0 --power 0.476 --fmax 165.7

### On hardware

    pip install pyserial
    # VALID build
    python3 host/host_driver.py --port /dev/ttyUSB0 --kernel sobel_x --image ramp
    # SAME build uses the same host driver and protocol shape (send kernel,
    # send pixels, receive results) -- only the FPGA bitstream differs.

---

## Toolchain notes

Built with Xilinx ISE 14.7 (XST, MAP, PAR, TRCE, XPower Analyzer). Both cores avoid patterns XST 14.7 rejects but Icarus accepts: `localparam` inside generate blocks, array elements in implicit sensitivity lists (`Xst:902`), for-loop bounds over arrays inside always blocks (`Xst:2634`), multi-driver registers (`Xst:528`), and reserved-keyword identifiers. All arithmetic and pipeline depth are unchanged from the originally verified design; only coding style was adjusted for synthesis.

N is fixed at 3 in both synthesised builds. Kernel *coefficients* remain runtime-programmable in both, as the specification requires.

---

## Status

### Complete

- [x] Golden model with derived bit-width analysis
- [x] VALID build: RTL, 72/72 core regression, system + multi-kernel tests
- [x] VALID build: synthesis, place and route, timing closure (score 0)
- [x] VALID build: DSP48E vs LUT-multiplier comparison, both fully implemented
- [x] SAME build: true zero-gap RTL, proven at the core level (0-cycle max gap)
- [x] SAME build: system test, saturation test, multi-kernel test — all bit-exact
- [x] SAME build: synthesis, place and route, timing closure (score 0)
- [x] Figure of Merit computed for both builds, trade-off reported honestly
- [x] Power analysis (XPower)
- [x] Bitstreams generated (both builds)
- [x] Block diagram and FSM state diagram
- [x] Simulation waveform captures
- [x] Progress report (PDF)
- [x] Presentation deck (12 slides)

### Remaining

- [ ] **Board demonstration** — bitstreams ready for both builds, hardware access in progress
- [ ] **Edge-detection demo on real imagery** *(optional bonus)*
- [ ] Copy SAME build's ISE reports into `fpga/reports_same/`
- [ ] Final report assembly incorporating the SAME-build results and bug-fix narrative
- [ ] Update presentation with the VALID-vs-SAME comparison table

**Deadline:** 15 September 2026

---

## License

Submitted as a student competition entry. Contact the author before reuse.
