import matplotlib.pyplot as plt
import os
import csv
import sys
import numpy as np
from statistics import median
from glob import glob
from pprint import pprint

# TODO: imprimir o 0 nos .csv, ta imprimindo nada, entao ele lê nada

def main():
    csv_dir = os.path.abspath(sys.argv[1])
    output_dir = os.path.abspath(sys.argv[2])

    for csv_file in sorted(glob(f'{csv_dir}/Tempos.csv')):
        with open(csv_file, newline='') as csvfile:
            csv_reader = csv.reader(csvfile)

            xpoints = []
            matvet_o = []
            matmat_o = []
            matvet = []
            matmat = []
            results = {
                    'matvet_o': {},
                    'matmat_o': {},
                    'matvet': {},
                    'matmat': {}
                    }
            for row in csv_reader:
                row0 = int(row[0])
                if row0 not in xpoints:
                    xpoints.append(row0)
                if row0 not in results['matvet_o']:
                    results['matvet_o'][row0] = []
                results['matvet_o'][row0].append(float(row[1]))

                if row0 not in results['matmat_o']:
                    results['matmat_o'][row0] = []
                results['matmat_o'][row0].append(float(row[2]))

                if row0 not in results['matvet']:
                    results['matvet'][row0] = []
                results['matvet'][row0].append(float(row[3]))

                if row0 not in results['matmat']:
                    results['matmat'][row0] = []
                results['matmat'][row0].append(float(row[4]))

            for funcao in results:
                aux = []
                for tamanho in results[funcao]:
                    aux.append(median(results[funcao][tamanho]))
                if str(funcao) == 'matvet_o':
                    matvet_o = aux
                elif str(funcao) == 'matmat_o':
                    matmat_o = aux
                elif str(funcao) == 'matvet':
                    matvet = aux
                elif str(funcao) == 'matmat':
                    matmat = aux

            plt.plot(xpoints, matvet, color='y', label='MatVet')
            plt.plot(xpoints, matmat, color='g', label='MatMat')
            plt.plot(xpoints, matvet_o, color='b', label='MatVet Otimizada')
            plt.plot(xpoints, matmat_o, color='r', label='MatMat Otimizada')

            plt.xlabel('N (bytes)')
            plt.ylabel('Milissegundos')
            plt.title('Tempos')
            plt.legend()
            plt.yscale('log')
            plt.savefig(f'{output_dir}/Tempos.png')
                        

if __name__=='__main__':
    main()
