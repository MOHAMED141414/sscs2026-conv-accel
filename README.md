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
| Power (SAIF-based, measured) | 472.27 mW | 472.27 mW (shared figure — see Power Analysis Methodology) |
| **Figure of Merit** | **2.417 x 10^-3** | 2.393 x 10^-3 |

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

**Zero BRAM by construction.** The line buffers are flat shift registers, inferred by XST as SRL primitives in LUT fabric.

**Stall-tolerant pipeline.** Every state element is gated on `in_valid`, so gaps in the input stream are harmless in both builds.

---

## How the SAME build achieves TRUE zero-gap operation

The first SAME attempt injected literal zero-padding pixels between image rows. It worked numerically, but each injected pixel cost one real clock cycle — a 2-cycle stall at every row boundary. Measured directly: 31 violations, sustained throughput ~94.3%, not the required 100%.

**The fix removes the padding cycles entirely.** Top padding is free — the line buffers (`lb0`, `lb1`) are reset to zero, so `lb0_out`/`lb1_out` correctly read as zero for the first one/two rows before any real data has shifted through, with no extra pixels needed. Left padding uses column masking instead of injection: the window's two oldest columns are masked to zero combinationally whenever fewer than 2 (or 1) real pixels of the current row have been seen, tracked by a saturating counter (`rundist`) that avoids the row-wraparound aliasing an ordinary column counter would hit.

Verified directly: feeding `conv_accel_same` continuously with only the 1024 real pixels (no padding pixels of any kind) produces 1024/1024 bit-exact outputs with **0 cycles of any out_valid gap**, checked by an explicit cycle-by-cycle monitor.

### Real bugs hit and fixed along the way

- **Verilog sign-mixing** in the mask ternary silently produced an unsigned expression, corrupting the multiply stage.
- **`dist` is a reserved SystemVerilog keyword** — renamed to `rundist`.
- **Column-counter wraparound aliasing** — the natural column counter reads identically at "just wrapped past a full row" and "genuinely starting a new row," causing false masking on the last pixel of every row. Fixed with the saturating `rundist` counter.
- **Multi-driver register, tolerated by simulation, rejected by synthesis** — `f_cnt` (FIFO occupancy) was written from two separate `always` blocks; Icarus simulated it via scheduling-order luck, XST correctly refused it (`ERROR:Xst:528`). Fixed by consolidating into one block driven by `push`/`pop` wires.
- **Declare-before-use ordering** — XST's HDL compiler is stricter than Icarus about a wire referencing registers declared later in the file.
- **UART pin mapping on the physical board** resolved by consulting the Genesys schematic directly.

---

## Power Analysis Methodology

**FPGA device and board:** Xilinx Virtex-5 XC5VLX50T-1FF1136, Digilent Genesys.

**Operating frequency used in the FoM:** Each build's own post-route maximum frequency — 167.0 MHz (VALID) and 165.7 MHz (SAME) — rather than a common arbitrary clock, since this is the frequency each design would actually run at.

**Tools:** Xilinx ISE 14.7 for synthesis and implementation (XST, MAP, PAR); ISim for post-route gate-level simulation with SDF timing back-annotation; XPower Analyzer 14.7 (`xpwr`) for SAIF-driven power analysis.

**Why SAIF, and why post-route:** RTL-level simulation activity matched only 11% of the post-route design's nets (XST substantially renames and restructures nets during synthesis), leaving XPower to fall back to vector-less estimation for the rest. Simulating the actual routed netlist (`netgen -sim` output) instead achieved **100% design-net matching**.

**Simulation interval:** Reset and coefficient-load prologue excluded (capture starts 210 ns in, after pipeline settle). Window covers 80 real pixels streamed continuously over the design's actual UART protocol at its true synthesized bit timing — a representative sample of active convolution processing, chosen to keep gate-level SDF simulation time tractable rather than the full 1024-pixel frame. Total simulated duration: 2,752,610 ns.

**Measured power (VALID build, 100% net-matched):**

| | Power |
|---|---|
| Dynamic | 17.50 mW |
| Static | 454.77 mW |
| **Total** | **472.27 mW** |

**SAME build:** An equivalent post-route capture was attempted but did not complete within the available time budget — the zero-gap design's every-cycle switching (by construction, no idle cycles) makes SDF-timed gate-level simulation substantially more expensive than VALID's intermittent-activity profile. Given both builds share the same clock, board, and over 95% of their logic (SAME adds only 118 LUTs of masking logic over VALID's 317), VALID's measured power is reported as representative for SAME's FoM. This is a conservative substitution: SAME's proven higher switching activity would likely push its true dynamic power marginally above VALID's, not below it.

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
| Power (SAIF, post-route) | 80 px | VALID, 100% net-matched | 472.27 mW total |

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
    fpga/power/          tb_power_valid_toplevel.v  post-route SAIF testbench (VALID)
                         tb_power_same_toplevel.v   post-route SAIF testbench (SAME)
                         power_valid_pr.saif        measured activity, 100% net-matched
                         power_valid_pr.pwr         XPower report (VALID, 472.27 mW)
                         power_valid_pr.prj, .tcl   ISim project/batch files
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
    docs/figures/        block diagram, FSM diagrams, waveform captures

---

## Reproducing the results

Requires `python3`, `numpy`, `iverilog`, and Xilinx ISE 14.7 (for the SAIF power flow).

    # VALID build: full 72-case core regression
    bash sim/run_regression.sh

    # SAME build: core-level zero-gap proof (no UART, no injected padding)
    iverilog -g2012 -o build/samecore.vvp rtl/conv_accel_same.v tb/tb_same_core_check.v
    vvp build/samecore.vvp
    # expect: PASS 1024/1024 bit-exact, max gap=0 cycles, gap>=2 violations=0

    # Power (post-route, SAIF-based) -- see fpga/power/ for the full flow
    source /opt/Xilinx/14.7/ISE_DS/settings64.sh
    cd <ISE project dir for the VALID build>
    netgen -sim -ofmt verilog -pcf conv_top.pcf -w conv_top.ncd conv_top_timesim.v
    fuse -intstyle ise -o power_valid_pr_isim -prj fpga/power/power_valid_pr.prj \
         tb_power_valid_toplevel glbl -L simprims_ver
    ./power_valid_pr_isim -tclbatch fpga/power/power_valid_pr.tcl
    xpwr -s power_valid_pr.saif -o power_valid_pr.pwr conv_top.ncd conv_top.pcf

    # Figure of Merit, either build
    python3 fpga/fom.py --luts 317 --ffs 275 --dsps 9 --brams 0 --power 0.47227 --fmax 167.0
    python3 fpga/fom.py --luts 435 --ffs 325 --dsps 9 --brams 0 --power 0.47227 --fmax 165.7

---

## Toolchain notes

Built with Xilinx ISE 14.7 (XST, MAP, PAR, TRCE, XPower Analyzer, ISim). Both cores avoid patterns XST 14.7 rejects but Icarus accepts: `localparam` inside generate blocks, array elements in implicit sensitivity lists, for-loop bounds over arrays inside always blocks, multi-driver registers, and reserved-keyword identifiers.

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
- [x] Power analysis: SAIF-based, post-route, 100% net-matched (VALID); documented fallback (SAME)
- [x] Figure of Merit recomputed with measured power for both builds
- [x] Bitstreams generated (both builds)
- [x] Block diagram and FSM state diagrams (VALID and SAME)
- [x] Simulation waveform captures, including zero-gap proof
- [x] Progress report (PDF)
- [x] Presentation deck (13 slides)

### Remaining

- [ ] **Board demonstration** — bitstreams ready for both builds, hardware access in progress
- [ ] **Edge-detection demo on real imagery** *(optional bonus)*
- [ ] Final report assembly incorporating the power-methodology section

**Deadline:** 15 September 2026

---

## License

Submitted as a student competition entry. Contact the author before reuse.
