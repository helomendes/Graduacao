import argparse
import yaml
import sys
import os

def main():
    metric = sys.argv[1]
    size = sys.argv[2]
    data = sys.argv[3] + '/' + metric + '_' + size + '.txt'

    metrics = {
            'MEM': 'mem bandwidth',
            'L3': 'L3 bandwidth',
            'CACHE': 'cache miss ratio',
            'L2CACHE': 'L2 miss ratio',
            'FLOPS_DP': 'DP MFLOP/s',
            'FLOPS_AVX': 'AVX DP MFLOP/s'
            }

    if os.path.isfile(data):
        os.system(f'echo -n "{size}"; cat {data} | egrep "{metrics[metric]}" | cut -d\',\' -f 2 | awk \'{{print}}\' ORS=\',\' | sed -e \'s;,$;;g\'')
        print()

if __name__ == "__main__":
	main()
