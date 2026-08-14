#!/usr/bin/env bash
# Full regression: every image x kernel x relu case from conv_golden.py
set -u

IMGS="random all_max all_zero v_edge ramp checker"
KERS="sobel_x sobel_y laplacian identity sat_neg sat_pos"

iverilog -g2012 -o build/sim.vvp rtl/conv_accel.v tb/tb_conv_accel.v || exit 1

pass=0; fail=0; failed=""
for img in $IMGS; do
  for ker in $KERS; do
    for relu in 0 1; do
      if [ "$relu" = "1" ]; then tag="${img}__${ker}__relu"; else tag="${img}__${ker}"; fi
      exp="vectors/exp_${tag}.hex"
      [ -f "$exp" ] || { echo "missing $exp"; continue; }
      out=$(vvp build/sim.vvp +IMG="vectors/img_${img}.hex" \
                    +KER="vectors/kernel_${ker}.hex" \
                    +EXP="$exp" +RELU=$relu 2>&1)
      if echo "$out" | grep -q "^PASS"; then
        pass=$((pass+1))
      else
        fail=$((fail+1)); failed="$failed $tag"
        echo "FAIL: $tag"
        echo "$out" | grep MISMATCH | head -3
      fi
    done
  done
done

echo "========================================================="
echo "REGRESSION: $pass passed, $fail failed  ($((pass+fail)) cases)"
[ $fail -gt 0 ] && echo "failing:$failed"
echo "========================================================="
exit $fail
