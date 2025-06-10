import subprocess
import argparse
import os
import random
import string
import csv
from tqdm import tqdm

def generate_file(leght, filename):
    with open(filename, 'w') as file:
        seq = ''.join(random.choices(string.ascii_lowercase, k=leght))
        file.write(seq)

def main():
    parse = argparse.ArgumentParser()
    parse.add_argument('-c', help='Código LCS em C', required=True)
    args = parse.parse_args()

    c_path = os.path.abspath(args.c)
    
    path = c_path.rsplit('/', 1)[0]
    out_path = os.path.join(path, "testep")
    fileA = os.path.join(path, "fileA.in")
    fileB = os.path.join(path, "fileB.in")
    csv_output = os.path.join(path, "output.csv")

    compilacao = subprocess.run(["gcc", c_path,"-fopenmp", "-O3", "-o", out_path], capture_output=True, text=True);
    if compilacao.returncode != 0:
        print("Erro ao compilar:\n", compilacao.stderr)
    else:
        csv_output = open(csv_output, 'w', newline='')
        csv_writer = csv.writer(csv_output, delimiter=' ', quotechar='|', quoting=csv.QUOTE_MINIMAL)
        header = ['Threads', 'N', 'Sequential Time', 'Parallel Time', 'Total Time']
        csv_writer = csv.DictWriter(csv_output, fieldnames=header)
        csv_writer.writeheader()

        num_threads = [1, 2, 4, 8]
        n_sizes = [10000, 20000, 30000]
        executions = 20

        for n in n_sizes:
            generate_file(n, fileA)
            generate_file(n, fileB)
            for nthreads in num_threads:
                mean_seq_time = 0
                mean_par_time = 0
                mean_time = 0
                print("\nExperiment:", nthreads, n)
                for i in tqdm(range(executions), desc=f'Computing...'):
                    execucao = subprocess.run([out_path, f'{nthreads}'], capture_output=True, text=True)
                    info = execucao.stdout.split('\n')
                    run_seq_time = float(info[3])
                    run_par_time = float(info[4])
                    run_time = float(info[5])

                    mean_seq_time += run_seq_time
                    mean_par_time += run_par_time
                    mean_time += run_time

                mean_seq_time /= executions 
                mean_par_time /= executions 
                mean_time /= executions 

                csv_writer.writerow({'Threads': nthreads, 'N': n, 'Sequential Time': mean_seq_time, 'Parallel Time': mean_par_time, 'Total Time': mean_time})

if __name__ == "__main__":
    main()
