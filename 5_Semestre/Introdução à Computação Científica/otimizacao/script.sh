#!/bin/bash

PROG=matmult
CPU=3

DATA_DIR="/home/bcc/hbm22/Results"

mkdir -p ${DATA_DIR}

echo "performance" > /sys/devices/system/cpu/cpufreq/policy${CPU}/scaling_gonvernor

make purge matmult

METRICAS="FLOPS_DP FLOPS_AVX L2CACHE L3"
TEMPOS="${DATA_DIR}/Tempos.csv"
TAMANHOS="64 100 128 200 256 512 600 900 1024 2000 2048"

for METRICA in ${METRICAS}; do
	LIKWID_LOG="${DATA_DIR}/${METRICA}.csv"
	for TAMANHO in ${TAMANHOS}; do
		LIKWID_OUT="${DATA_DIR}/${METRICA}_${TAMANHO}.txt"
		echo "---> ${METRICA} ./${PROG} ${TAMANHO}"
		likwid-perfctr -O -C ${CPU} -g ${METRICA} -o ${LIKWID_OUT} -m ./${PROG} ${TAMANHO} >> ${TEMPOS}

		python3 filter.py ${METRICA} ${TAMANHO} ${DATA_DIR} >> ${LIKWID_LOG}

	done
done

echo "powersave" > /sys/devices/system/cpu/cpufreq/policy${CPU}/scaling_governor
