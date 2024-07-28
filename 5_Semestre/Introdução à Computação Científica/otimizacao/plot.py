import matplotlib.pyplot as plt
import os
from glob import glob

def main():
    csv_dir = '/home/bcc/hbm22/Results/'
    csv_dir = os.path.abspath(csv_dir)

    print(csv_dir)
    for csv in glob(csv_dir):
        print('a')
        print(csv)

if __name__=='__main__':
    main()
