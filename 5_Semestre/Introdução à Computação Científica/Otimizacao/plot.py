import matplotlib.pyplot as plt
import os
import csv
import sys
import numpy as np
from glob import glob

# TODO: imprimir o 0 nos .csv, ta imprimindo nada, entao ele lê nada

def main():
    csv_dir = os.path.abspath(sys.argv[1])
    metric = sys.argv[2]
    output_dir = os.path.abspath(sys.argv[3])

    metrics = {
            'MEM': 'mem bandwidth',
            'L3': 'L3 bandwidth',
            'CACHE': 'cache miss ratio',
            'L2CACHE': 'L2 miss ratio',
            'FLOPS_DP': 'DP MFLOP/s',
            'FLOPS_AVX': 'AVX DP MFLOP/s',
            'ENERGY': 'Energy [J]'
            }
    flops = False
    if metric == 'FLOPS_DP':
        flops = True

    for csv_file in sorted(glob(f'{csv_dir}/{metric}.csv')):

        with open(csv_file, newline='') as csvfile:
            csv_reader = csv.reader(csvfile)
            xpoints = []
            matvet = []
            matmat = []
            matvet_o = []
            matmat_o = []
            if flops:
                matvet_o_avx = []
                matmat_o_avx = []
                matvet_avx = []
                matmat_avx = []

            for row in csv_reader:
                xpoints.append(int(row[0]))
                if flops:
                    matvet_o.append(float(row[1]))
                    matmat_o.append(float(row[3]))
                    matvet.append(float(row[5]))
                    matmat.append(float(row[7]))
                    matvet_o_avx.append(float(row[2]))
                    matmat_o_avx.append(float(row[4]))
                    matvet_avx.append(float(row[6]))
                    matmat_avx.append(float(row[8]))
                else:
                    matvet_o.append(float(row[1]))
                    matmat_o.append(float(row[2]))
                    matvet.append(float(row[3]))
                    matmat.append(float(row[4]))

            plt.plot(xpoints, matvet, color='y', label='MatVet')
            plt.plot(xpoints, matmat, color='g', label='MatMat')
            plt.plot(xpoints, matvet_o, color='b', label='MatVet Otimizada')
            plt.plot(xpoints, matmat_o, color='r', label='MatMat Otimizada')

            plt.xlabel('N (bytes)')
            plt.ylabel(metrics[metric])
            plt.title(metric)
            plt.legend()
            plt.yscale('log')
            plt.savefig(f'{output_dir}/{metric}.png')

            if flops:
                plt.clf()

                plt.plot(xpoints, matvet_avx, color='y', label='MatVet')
                plt.plot(xpoints, matmat_avx, color='g', label='MatMat')
                plt.plot(xpoints, matvet_o_avx, color='b', label='MatVet Otimizada')
                plt.plot(xpoints, matmat_o_avx, color='r', label='MatMat Otimizada')

                plt.xlabel('N (bytes)')
                plt.ylabel(metrics['FLOPS_AVX'])
                plt.title('FLOPS_AVX')
                plt.legend()
                plt.yscale('log')
                plt.savefig(f'{output_dir}/FLOPS_AVX.png')
                        

if __name__=='__main__':
    main()
