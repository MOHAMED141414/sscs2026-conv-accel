#!/usr/bin/env python3
"""
host_driver.py - Host-side driver for the FPGA convolution accelerator
IEEE SSCS Egypt Chapter 2026 Student Design Competition

Implements the request-response protocol in conv_top.v:
  1. send N*N kernel bytes (int8, row-major)
  2. send pixels one at a time; for each pixel with row>=N-1 and col>=N-1
     read back 2 bytes (int16 big-endian) before sending the next

Usage
-----
  # verify the protocol logic with no board attached
  python3 host/host_driver.py --dry-run --kernel sobel_x --image ramp

  # run against the board
  python3 host/host_driver.py --port /dev/ttyUSB0 --kernel sobel_x --image ramp

  # edge-detection demo on a real picture (needs Pillow)
  python3 host/host_driver.py --port /dev/ttyUSB0 --kernel sobel_x \\
          --image-file smear.png --out smear_edges.pgm

Dependencies: numpy (required), pyserial (board mode), Pillow (--image-file)
"""

import argparse
import sys
import time
from pathlib import Path

import numpy as np

sys.path.insert(0, str(Path(__file__).resolve().parent.parent / "golden"))
from conv_golden import conv2d_golden, KERNELS, make_test_images  # noqa: E402

IMG_W = IMG_H = 32
N = 3
OUT_W = IMG_W - N + 1
OUT_H = IMG_H - N + 1


# ------------------------------------------------------------------ helpers
def output_positions(w=IMG_W, h=IMG_H, n=N):
    """Linear pixel indices that complete a window (and so produce output)."""
    return {r * w + c for r in range(n - 1, h) for c in range(n - 1, w)}


def load_image(args):
    """Return a (IMG_H, IMG_W) uint8 array from the requested source."""
    if args.image_file:
        try:
            from PIL import Image
        except ImportError:
            sys.exit("--image-file needs Pillow:  pip install pillow")
        im = Image.open(args.image_file).convert("L").resize(
            (IMG_W, IMG_H), Image.LANCZOS)
        return np.array(im, dtype=np.uint8)

    imgs = make_test_images(IMG_W)
    if args.image not in imgs:
        sys.exit(f"unknown --image {args.image}; choose from {list(imgs)}")
    return imgs[args.image]


def load_kernel(name):
    if name not in KERNELS:
        sys.exit(f"unknown --kernel {name}; choose from {list(KERNELS)}")
    return KERNELS[name]


def write_pgm(path, arr):
    """Write a normalised 8-bit PGM. No external deps."""
    a = np.asarray(arr, dtype=np.int32)
    lo, hi = int(a.min()), int(a.max())
    norm = np.zeros_like(a, dtype=np.uint8) if hi == lo else \
        (((a - lo) * 255) // (hi - lo)).astype(np.uint8)
    with open(path, "wb") as f:
        f.write(f"P5\n{norm.shape[1]} {norm.shape[0]}\n255\n".encode())
        f.write(norm.tobytes())


# ------------------------------------------------------------------ transport
class DryRunLink:
    """Stands in for the board: answers from the golden model.

    Exercises the exact byte sequencing the serial path uses, so protocol
    bugs surface without hardware.
    """

    def __init__(self, kernel, relu):
        self.kernel = kernel
        self.relu = relu
        self.pixels = []
        self.pending = bytearray()
        self.coeffs_seen = 0
        self.expected = None

    def write(self, data):
        for b in data:
            if self.coeffs_seen < N * N:
                self.coeffs_seen += 1
                continue
            self.pixels.append(b)
            idx = len(self.pixels) - 1
            r, c = divmod(idx, IMG_W)
            if r >= N - 1 and c >= N - 1:
                if self.expected is None and len(self.pixels) == IMG_W * IMG_H:
                    pass
                # compute lazily once the full frame is known is not possible
                # here, so compute per-window directly
                top = r - (N - 1)
                left = c - (N - 1)
                win = np.array(
                    [[self.pixels[(top + i) * IMG_W + (left + j)]
                      for j in range(N)] for i in range(N)], dtype=np.int32)
                acc = int((win * self.kernel.astype(np.int32)).sum())
                val = max(-32768, min(32767, acc))
                if self.relu:
                    val = max(0, val)
                self.pending += int(val & 0xFFFF).to_bytes(2, "big")

    def read(self, n):
        out, self.pending = self.pending[:n], self.pending[n:]
        return bytes(out)


def open_link(args, kernel):
    if args.dry_run:
        return DryRunLink(kernel, args.relu)
    try:
        import serial
    except ImportError:
        sys.exit("board mode needs pyserial:  pip install pyserial")
    return serial.Serial(args.port, args.baud, timeout=args.timeout)


# ------------------------------------------------------------------ protocol
def run(link, img, kernel, relu, verbose=True):
    outpos = output_positions()
    results = []

    # 1) kernel coefficients, row-major, as signed bytes
    link.write(bytes(int(v) & 0xFF for v in kernel.flatten()))

    # 2) pixel stream with inline readback
    flat = img.flatten()
    t0 = time.time()
    for i, px in enumerate(flat):
        link.write(bytes([int(px)]))
        if i in outpos:
            resp = link.read(2)
            if len(resp) != 2:
                raise RuntimeError(
                    f"timeout at pixel {i} ({len(results)} results so far). "
                    "Check baud rate, cable, and that the board was reset.")
            results.append(int.from_bytes(resp, "big", signed=True))
        if verbose and i % 256 == 0:
            print(f"\r  pixel {i}/{len(flat)}  results {len(results)}",
                  end="", flush=True)
    if verbose:
        print(f"\r  pixel {len(flat)}/{len(flat)}  results {len(results)}"
              f"   ({time.time()-t0:.1f}s)")

    if len(results) != OUT_W * OUT_H:
        raise RuntimeError(f"got {len(results)} results, expected {OUT_W*OUT_H}")
    return np.array(results, dtype=np.int16).reshape(OUT_H, OUT_W)


# ------------------------------------------------------------------ main
def main():
    p = argparse.ArgumentParser(description=__doc__,
                                formatter_class=argparse.RawDescriptionHelpFormatter)
    p.add_argument("--port", default="/dev/ttyUSB0")
    p.add_argument("--baud", type=int, default=115200)
    p.add_argument("--timeout", type=float, default=2.0)
    p.add_argument("--dry-run", action="store_true",
                   help="no board; answer from the golden model")
    p.add_argument("--kernel", default="sobel_x", choices=list(KERNELS))
    p.add_argument("--image", default="ramp",
                   help="built-in test image name")
    p.add_argument("--image-file", help="real image file (needs Pillow)")
    p.add_argument("--relu", action="store_true",
                   help="board switch must match this setting")
    p.add_argument("--out", help="write result as PGM")
    p.add_argument("--out-in", help="write the 32x32 input as PGM too")
    args = p.parse_args()

    img = load_image(args)
    ker = load_kernel(args.kernel)

    print(f"kernel : {args.kernel}\n{ker}")
    print(f"image  : {args.image_file or args.image}  {img.shape}  "
          f"range [{img.min()}, {img.max()}]")
    print(f"relu   : {args.relu}")
    print(f"link   : {'DRY RUN (golden model)' if args.dry_run else args.port}")
    print()

    link = open_link(args, ker)
    if not args.dry_run:
        time.sleep(0.2)
        link.reset_input_buffer()

    hw = run(link, img, ker, args.relu)
    gold, _ = conv2d_golden(img, ker, relu=args.relu)

    diff = (hw != gold)
    nbad = int(diff.sum())
    print()
    print(f"hardware output : {hw.shape}  range [{hw.min()}, {hw.max()}]")
    print(f"golden output   : {gold.shape}  range [{gold.min()}, {gold.max()}]")
    if nbad == 0:
        print(f"RESULT: PASS  {hw.size}/{hw.size} pixels bit-exact")
    else:
        print(f"RESULT: FAIL  {nbad}/{hw.size} mismatched")
        ys, xs = np.nonzero(diff)
        for y, x in list(zip(ys, xs))[:8]:
            print(f"   ({y},{x}) hw={hw[y,x]} gold={gold[y,x]}")

    if args.out:
        write_pgm(args.out, hw)
        print(f"wrote {args.out}")
    if args.out_in:
        write_pgm(args.out_in, img)
        print(f"wrote {args.out_in}")

    return 0 if nbad == 0 else 1


if __name__ == "__main__":
    sys.exit(main())
