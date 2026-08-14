#!/usr/bin/env python3
"""
fom.py - Figure of Merit calculator
IEEE SSCS Egypt Chapter 2026 Student Design Competition

    FOM = Throughput / (Power x (LUTs + 50*DSPs + 100*BRAMs))

with throughput in OUTPUT PIXELS PER CYCLE.

Usage
-----
  python3 fpga/fom.py --luts 620 --ffs 410 --dsps 9 --brams 0 \
                      --power 0.516 --fmax 103.5

  # compare two synthesis runs
  python3 fpga/fom.py --compare
"""

import argparse

IMG_W = IMG_H = 32
N = 3
OW, OH = IMG_W - N + 1, IMG_H - N + 1
NPIX = IMG_W * IMG_H          # 1024 input pixels
NOUT = OW * OH                # 900 output pixels
PIPE = 4                      # core pipeline depth (window -> out_valid)


def throughput_analysis():
    """
    Two defensible throughput figures - report BOTH.

    PEAK: within a row, once the window is full, the core retires one output
    every cycle. That is the architectural claim: 1.0 output px/cycle.

    SUSTAINED: over a whole frame, the first N-1 rows and the first N-1
    columns of every row produce no output (VALID border). So 900 outputs
    come out of 1024 input cycles plus pipeline drain. This is the honest
    frame-level number and the one to use in the FoM.
    """
    first_out = (N - 1) * IMG_W + (N - 1) + PIPE     # cycles to first output
    total = NPIX + PIPE                              # cycles to drain a frame
    return {
        "peak_px_per_cycle": 1.0,
        "sustained_px_per_cycle": NOUT / total,
        "cycles_per_frame": total,
        "first_output_latency_cycles": first_out,
        "outputs": NOUT,
        "inputs": NPIX,
    }


def fom(throughput, power_w, luts, dsps, brams):
    denom_res = luts + 50 * dsps + 100 * brams
    if power_w <= 0 or denom_res <= 0:
        raise ValueError("power and resource cost must be positive")
    return throughput / (power_w * denom_res), denom_res


def report(name, luts, ffs, dsps, brams, power_w, fmax_mhz):
    t = throughput_analysis()
    th = t["sustained_px_per_cycle"]
    f_sus, denom = fom(th, power_w, luts, dsps, brams)
    f_peak, _ = fom(t["peak_px_per_cycle"], power_w, luts, dsps, brams)

    print(f"=== {name} ===")
    print(f"  LUTs {luts}   FFs {ffs}   DSPs {dsps}   BRAMs {brams}")
    print(f"  Resource cost  = {luts} + 50x{dsps} + 100x{brams} = {denom}")
    print(f"  Power          = {power_w*1000:.0f} mW")
    print(f"  Fmax           = {fmax_mhz} MHz")
    print(f"  Throughput     = {th:.4f} out px/cycle sustained "
          f"({t['peak_px_per_cycle']:.1f} peak)")
    if fmax_mhz:
        print(f"                 = {th*fmax_mhz:.2f} Mpixel/s at Fmax")
        print(f"  Frame time     = {t['cycles_per_frame']/(fmax_mhz*1e6)*1e6:.2f} us "
              f"({t['cycles_per_frame']} cycles)")
    print(f"  First output   = {t['first_output_latency_cycles']} cycles")
    print(f"  FOM (sustained)= {f_sus:.3e}")
    print(f"  FOM (peak)     = {f_peak:.3e}")
    print()
    return f_sus


def main():
    p = argparse.ArgumentParser()
    p.add_argument("--luts", type=int)
    p.add_argument("--ffs", type=int, default=0)
    p.add_argument("--dsps", type=int, default=0)
    p.add_argument("--brams", type=int, default=0)
    p.add_argument("--power", type=float, help="TOTAL on-chip power in WATTS")
    p.add_argument("--fmax", type=float, default=0.0)
    p.add_argument("--name", default="synthesis run")
    p.add_argument("--compare", action="store_true",
                   help="worked example: DSP vs LUT multipliers")
    a = p.parse_args()

    t = throughput_analysis()
    print("Throughput analysis (32x32 input, 3x3 kernel, VALID border)")
    print(f"  {t['inputs']} input pixels -> {t['outputs']} output pixels")
    print(f"  {t['cycles_per_frame']} cycles per frame")
    print(f"  sustained {t['sustained_px_per_cycle']:.4f} out px/cycle, "
          f"peak {t['peak_px_per_cycle']:.1f}")
    print()

    if a.compare:
        print("WORKED EXAMPLE - replace with your real ISE numbers.\n")
        report("A: DSP48E multipliers (XST default)",
               luts=200, ffs=400, dsps=9, brams=0, power_w=0.516, fmax_mhz=103.5)
        report("B: LUT multipliers (DSP ratio = 0)",
               luts=650, ffs=400, dsps=0, brams=0, power_w=0.500, fmax_mhz=95.0)
        print("Whichever gives the higher FoM is the one to deploy - but report")
        print("both, and say why. The 50x DSP penalty means option B can win")
        print("even though it uses far more LUTs.")
        return

    if a.luts is None or a.power is None:
        p.error("need --luts and --power (or use --compare)")
    report(a.name, a.luts, a.ffs, a.dsps, a.brams, a.power, a.fmax)


if __name__ == "__main__":
    main()
