#!/usr/bin/env python3
"""
Golden reference model - NxN CNN convolution accelerator
IEEE SSCS Egypt Chapter 2026 Student Design Competition

Defines the bit-exact fixed-point semantics the RTL must match, and emits
test vectors / expected outputs for the Verilog testbench.

Datapath contract (must match RTL exactly):
    input pixel   : uint8   (Q8.0 unsigned)
    kernel coeff  : int8    (Q8.0 signed, programmable)
    product       : int16   ( 8u x 8s -> 16 bits, exact)
    accumulator   : int32   (N*N products; 20 bits suffices for N=3, 32 is free in sim)
    output        : int16   with SATURATION (not wraparound)
    ReLU          : optional, applied AFTER saturation
    stride        : 1
    border        : VALID (no padding) -> out = (H-N+1) x (W-N+1)
"""

import numpy as np
from pathlib import Path

INT16_MIN, INT16_MAX = -32768, 32767


# ---------------------------------------------------------------- kernels
KERNELS = {
    # Sobel X - the edge-detection bonus demo
    "sobel_x": np.array([[-1, 0, 1],
                         [-2, 0, 2],
                         [-1, 0, 1]], dtype=np.int8),
    "sobel_y": np.array([[-1, -2, -1],
                         [ 0,  0,  0],
                         [ 1,  2,  1]], dtype=np.int8),
    "laplacian": np.array([[0,  1, 0],
                           [1, -4, 1],
                           [0,  1, 0]], dtype=np.int8),
    "identity": np.array([[0, 0, 0],
                          [0, 1, 0],
                          [0, 0, 0]], dtype=np.int8),
    # Worst case for the accumulator: every tap at -128 against pixel 255
    "sat_neg": np.full((3, 3), -128, dtype=np.int8),
    # Worst case positive: 9 * 255 * 127 = 291465 -> must saturate to +32767
    "sat_pos": np.full((3, 3), 127, dtype=np.int8),
}


def saturate_int16(acc):
    """Clamp to int16. RTL must implement this, NOT truncation."""
    return np.clip(acc, INT16_MIN, INT16_MAX).astype(np.int16)


def conv2d_golden(img, kernel, relu=False):
    """
    Reference convolution. Cross-correlation (no kernel flip) - this is what
    CNN 'convolution' means and what the RTL window generator will do.
    """
    img = np.asarray(img, dtype=np.int32)      # promote, keep values 0..255
    ker = np.asarray(kernel, dtype=np.int32)
    N = ker.shape[0]
    H, W = img.shape
    OH, OW = H - N + 1, W - N + 1

    acc = np.zeros((OH, OW), dtype=np.int32)
    for i in range(OH):
        for j in range(OW):
            window = img[i:i + N, j:j + N]
            acc[i, j] = int(np.sum(window * ker))

    out = saturate_int16(acc)
    if relu:
        out = np.maximum(out, 0).astype(np.int16)
    return out, acc


def accumulator_width_analysis(N=3):
    """Bit-width justification for the report."""
    worst_pos = N * N * 255 * 127
    worst_neg = N * N * 255 * -128
    bits = int(np.ceil(np.log2(max(abs(worst_pos), abs(worst_neg)))) + 1)
    return {
        "N": N,
        "worst_case_positive": worst_pos,
        "worst_case_negative": worst_neg,
        "min_accumulator_bits": bits,
        "saturation_required": worst_pos > INT16_MAX or worst_neg < INT16_MIN,
    }


# ---------------------------------------------------------------- test images
def make_test_images(size=32, seed=42):
    rng = np.random.default_rng(seed)
    imgs = {}

    imgs["random"] = rng.integers(0, 256, (size, size), dtype=np.uint8)
    imgs["all_max"] = np.full((size, size), 255, dtype=np.uint8)
    imgs["all_zero"] = np.zeros((size, size), dtype=np.uint8)

    # Vertical step edge - Sobel X should light up hard on the boundary
    step = np.zeros((size, size), dtype=np.uint8)
    step[:, size // 2:] = 255
    imgs["v_edge"] = step

    # Diagonal ramp - catches window-generator addressing bugs
    ramp = np.fromfunction(lambda y, x: (x + y) * 4 % 256, (size, size))
    imgs["ramp"] = ramp.astype(np.uint8)

    # Checkerboard - stresses the line buffers
    chk = np.indices((size, size)).sum(axis=0) % 2 * 255
    imgs["checker"] = chk.astype(np.uint8)

    return imgs


# ---------------------------------------------------------------- emitters
def write_hex(path, arr, width_nibbles):
    """One value per line, hex, for Verilog $readmemh."""
    flat = np.asarray(arr).flatten()
    with open(path, "w") as f:
        for v in flat:
            f.write(f"{int(v) & ((1 << (width_nibbles * 4)) - 1):0{width_nibbles}x}\n")


def emit_vectors(outdir="vectors", size=32):
    out = Path(outdir)
    out.mkdir(exist_ok=True)
    imgs = make_test_images(size)
    manifest = []

    for iname, img in imgs.items():
        write_hex(out / f"img_{iname}.hex", img, 2)          # uint8
        for kname, ker in KERNELS.items():
            for relu in (False, True):
                res, acc = conv2d_golden(img, ker, relu=relu)
                tag = f"{iname}__{kname}{'__relu' if relu else ''}"
                write_hex(out / f"exp_{tag}.hex", res, 4)     # int16 two's comp
                manifest.append({
                    "image": iname, "kernel": kname, "relu": relu,
                    "out_shape": res.shape,
                    "acc_min": int(acc.min()), "acc_max": int(acc.max()),
                    "saturated": int(np.sum((acc > INT16_MAX) | (acc < INT16_MIN))),
                })

    for kname, ker in KERNELS.items():
        write_hex(out / f"kernel_{kname}.hex", ker.astype(np.int16), 2)

    return manifest


if __name__ == "__main__":
    print("=== Accumulator bit-width analysis ===")
    for N in (3, 5, 7):
        print(f"  {accumulator_width_analysis(N)}")

    print("\n=== Emitting test vectors ===")
    man = emit_vectors()
    print(f"  {len(man)} test cases written to ./vectors/")

    print("\n=== Saturation coverage (cases that actually clamp) ===")
    hits = [m for m in man if m["saturated"] > 0]
    for m in hits[:8]:
        print(f"  {m['image']:9s} x {m['kernel']:10s} relu={int(m['relu'])} "
              f"acc=[{m['acc_min']:8d},{m['acc_max']:8d}] clamped={m['saturated']}")
    print(f"  ... {len(hits)} of {len(man)} cases exercise saturation")

    print("\n=== Sanity: identity kernel must reproduce the image interior ===")
    img = make_test_images()["random"]
    res, _ = conv2d_golden(img, KERNELS["identity"])
    assert np.array_equal(res, img[1:-1, 1:-1].astype(np.int16))
    print("  PASS")

    print("\n=== Sobel X on vertical edge ===")
    res, _ = conv2d_golden(make_test_images()["v_edge"], KERNELS["sobel_x"])
    print(f"  output {res.shape}, range [{res.min()}, {res.max()}]")
