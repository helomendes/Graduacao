import os
import csv
import glob
import argparse
import pprint
import numpy as np

def read(size, arq, dic):
    parallel = False
    total_par_time = 0
    total_seq_time = 0
    seq_time = 0
    par_time = 0
    with open(arq, 'r') as file:
        line = file.readline()
        while line:
            if size not in dic:
                dic[size] = {}

            if "sequential" in line:
                parallel = False
            if "parallel" in line:
                parallel = True

            if not parallel:
                if "sequential" not in dic[size]:
                    dic[size]["sequential"] = {}
                if "Total time" in line:
                    total_seq_time = max(total_seq_time, float(line.split(' ')[-1]))
                    dic[size]["sequential"]["total_time"] = total_seq_time
                if "LCS time" in line:
                    seq_time = max(seq_time, float(line.split(' ')[-1]))
                    dic[size]["sequential"]["seq_time"] = seq_time
            else:
                if "EXEC" in line:
                    exc = line.split(' ')[1].rstrip('\n')
                    config = line.split(' ')[3].rstrip('\n')
                if "NUM_THREADS" in line:
                    nth = line.split(' ')[-1].rstrip('\n')
                    if nth not in dic[size]:
                        dic[size][nth] = {}
                if "SCHED" in line:
                    sched = line.split(' ')[-1].rstrip('\n')
                    if sched not in dic[size][nth]:
                        dic[size][nth][sched] = {}
                if "CHUNK" in line:
                    chunk = line.split(' ')[-1].rstrip('\n')
                    if chunk not in dic[size][nth][sched]:
                        dic[size][nth][sched][chunk] = {"total_time" : [], "par_time" : []}
                if "Total time" in line:
                    total_par_time = max(total_par_time, float(line.split(' ')[-1]))
                    dic[size][nth][sched][chunk]["total_time"].append(total_par_time)
                if "LCS time" in line:
                    par_time = max(par_time, float(line.split(' ')[-1]))
                    dic[size][nth][sched][chunk]["par_time"].append(par_time)

            line = file.readline()
        #pprint.pprint(dic)

def mean(size, mean_dic, raw_dic):
    ret = 0
    if size not in mean_dic:
        mean_dic[size] = {}
    for nt in raw_dic[size]:
        if nt == "sequential":
            times = [0,0]
            i = 0
            for time in raw_dic[size][nt]:
                times[i] = raw_dic[size][nt][time]
                i += 1
            ret = (times[1]*100)/times[0]
            continue
        if nt not in mean_dic:
            mean_dic[size][nt] = {}
        par_data = []
        total_data = []
        par_d_p = 0
        par_mean = 0
        total_d_p = 0
        total_mean = 0
        for sched in raw_dic[size][nt]:
            if sched not in mean_dic[size][nt]:
                mean_dic[size][nt][sched] = {}
            for chunk in raw_dic[size][nt][sched]:
                if chunk not in mean_dic[size][nt][sched]:
                    mean_dic[size][nt][sched][chunk] = {}
                for time in raw_dic[size][nt][sched][chunk]:
                    if time == "total_time":
                        total_data += raw_dic[size][nt][sched][chunk][time]
                    elif time == "par_time":
                        par_data += raw_dic[size][nt][sched][chunk][time]
                if len(par_data) > 0:
                    par_d_p = np.std(par_data)
                    par_mean = np.mean(par_data)
                if "par_time" not in mean_dic[size][nt][sched][chunk]:
                    mean_dic[size][nt][sched][chunk]["par_time"] = {}
                mean_dic[size][nt][sched][chunk]["par_time"]["std_dev"] = par_d_p
                mean_dic[size][nt][sched][chunk]["par_time"]["mean"] = par_mean

                if len(total_data) > 0:
                    total_d_p = np.std(total_data)
                    total_mean = np.mean(total_data)
                if "total_time" not in mean_dic[size][nt][sched][chunk]:
                    mean_dic[size][nt][sched][chunk]["total_time"] = {}
                mean_dic[size][nt][sched][chunk]["total_time"]["std_dev"] = total_d_p
                mean_dic[size][nt][sched][chunk]["total_time"]["mean"] = total_mean

    #pprint.pprint(mean_dic)

    return ret

def write_csv(mean_dic, csv_writer):
    for size in mean_dic:
        for nth in mean_dic[size]:
            for sched in mean_dic[size][nth]:
                for chunk in mean_dic[size][nth][sched]:
                    for time in mean_dic[size][nth][sched][chunk]:
                        for typ in mean_dic[size][nth][sched][chunk][time]:
                            csv_writer.writerow({'Size': size,
                                                 'Threads': nth,
                                                 'Sched': sched,
                                                 'Chunk': chunk,
                                                 'Time': time,
                                                 'Type': typ,
                                                 'Value': mean_dic[size][nth][sched][chunk][time][typ]})

def metricas(raw_dic, mean_dic, per_dic, su_dic, ef_dic, sum_dic, csv_writer):
    for size in raw_dic:
        ret = mean(size, mean_dic, raw_dic)
        write_csv(mean_dic, csv_writer)

        if size not in per_dic:
            per_dic[size] = {}
        if size not in su_dic:
            su_dic[size] = {}
        if size not in ef_dic:
            ef_dic[size] = {}
        if size not in sum_dic:
            sum_dic[size] = {}

        stime = raw_dic[size]["sequential"]["seq_time"]

        per_dic[size]["sequential"] = ret

        for nth in mean_dic[size]:
            if nth not in per_dic[size]:
                per_dic[size][nth] = {}
            if nth not in su_dic[size]:
                su_dic[size][nth] = {}
            if nth not in ef_dic[size]:
                ef_dic[size][nth] = {}
            if nth not in sum_dic[size]:
                sum_dic[size][nth] = {}

            for sched in mean_dic[size][nth]:
                if sched not in per_dic[size][nth]:
                    per_dic[size][nth][sched] = {}
                if sched not in su_dic[size][nth]:
                    su_dic[size][nth][sched] = {}
                if sched not in ef_dic[size][nth]:
                    ef_dic[size][nth][sched] = {}
                if sched not in sum_dic[size][nth]:
                    sum_dic[size][nth][sched] = {}

                for chunk in mean_dic[size][nth][sched]:
                    sum_dic[size][nth][sched][chunk] = (1 / ((1 - ret/100) + (ret/100 / int(nth))))

                    times = [0,0]
                    i = 0
                    for time in mean_dic[size][nth][sched][chunk]:
                        times[i] = mean_dic[size][nth][sched][chunk][time]["mean"]
                        i += 1
                    if times[1] > 0:
                        per_dic[size][nth][sched][chunk] = (times[0]*100)/times[1]
                    else:
                        per_dic[size][nth][sched][chunk] = 0

                    ptime = mean_dic[size][nth][sched][chunk]["par_time"]["mean"]

                    if ptime > 0:
                        su_dic[size][nth][sched][chunk] = stime / ptime
                    else:
                        su_dic[size][nth][sched][chunk] = 0
                    ef_dic[size][nth][sched][chunk] = su_dic[size][nth][sched][chunk] / int(nth)
def main():
    parse = argparse.ArgumentParser()
    parse.add_argument('-d', help='Directory with files to be read', required=True)
    args = parse.parse_args()

    path = os.path.abspath(args.d) + '/'
    files = glob.glob(f'{path}/*.out')

    csv_name = 'data.csv'
    csv_out = open(csv_name, 'w', newline='')
    csv_writer = csv.writer(csv_out, delimiter=' ', quotechar='|', quoting=csv.QUOTE_MINIMAL)
    header = ['Size', 'Threads', 'Sched', 'Chunk', 'Time', 'Type', 'Value']
    csv_writer = csv.DictWriter(csv_out, fieldnames=header)
    csv_writer.writeheader()

    raw_dic = {}
    mean_dic = {}
    per_dic = {}
    su_dic = {}
    ef_dic = {}
    sum_dic = {}

    for arq in files:
        size = arq.split('/')[-1].split('_')[0]
        read(size, arq, raw_dic)

    metricas(raw_dic, mean_dic, per_dic, su_dic, ef_dic, sum_dic, csv_writer)

    best = {}

    for size in raw_dic:
        best_per = []
        best_su = []
        best_ef = []
        best_mean = []
        if size not in best:
            best[size] = {}
        for nth in raw_dic[size]:
            if nth == 'sequential':
                continue
            for sched in raw_dic[size][nth]:
                for chunk in raw_dic[size][nth][sched]:
                    per = per_dic[size][nth][sched][chunk]
                    su = su_dic[size][nth][sched][chunk]
                    ef = ef_dic[size][nth][sched][chunk]
                    if per > 0:
                        if not best_per:
                            best_per = [size, nth, sched, chunk, per]
                        elif per < best_per[4]:
                            best_per = [size, nth, sched, chunk, per]
                    if su > 0:
                        if not best_su:
                            best_su = [size, nth, sched, chunk, su]
                        elif su > best_su[4]:
                            best_su = [size, nth, sched, chunk, su]
                    if ef > 0:
                        if not best_ef:
                            best_ef = [size, nth, sched, chunk, ef]
                        elif ef > best_ef[4]:
                            best_ef = [size, nth, sched, chunk, ef]

                    mean = mean_dic[size][nth][sched][chunk]["par_time"]["mean"]

                    if mean > 0:
                        if not best_mean:
                            best_mean = [size, nth, sched, chunk, mean]
                        elif mean < best_mean[4]:
                            best_mean = [size, nth, sched, chunk, mean]

        best[size]["percentage"] = best_per
        best[size]["speed_up"] = best_su
        best[size]["eficiency"] = best_ef
        best[size]["parallel_time"] = best_mean

    pprint.pprint(best)

    #print("Porcentagem de tempo")
    #pprint.pprint(per_dic)
    print("Speed Up")
    pprint.pprint(su_dic)
    #print("Eficiência")
    #pprint.pprint(ef_dic)
    #print("Speed Up Máximo Teórico")
    #pprint.pprint(sum_dic)


if __name__=="__main__":
    main()
