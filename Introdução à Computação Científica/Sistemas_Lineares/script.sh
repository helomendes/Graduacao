#!/bin/bash

echo "performance" > /sys/devices/system/cpu/cpufreq/policy3/scaling_governor

./perfSL < sl.dat
likwid-perfctr -C 0 -g FLOPS_DP -m ./perfSL < ../sl.dat | grep -e 'Region' -e 'FP_ARITH_INST_RETIRED_SCALAR_DOUBLE' -e 'DP' | grep -v 'Region Info' | grep -v 'AVX' 

echo "powersave" > /sys/devices/system/cpu/cpufreq/policy3/scaling_governor
