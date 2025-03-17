import argparse
import yaml
import os
import cv2 as cv
import numpy as np
import matplotlib.pyplot as plt

def main():
    parser = argparse.ArgumentParser()
    parser.add_argument('--config', help="Configuration YAML file")
    args = parser.parse_args()
    
    with open(args.config, 'r') as file:
        config = yaml.safe_load(file)

    imgs_dir = os.path.abspath(config.get('images_dir')) + '/'
    dest_dir = os.path.abspath(config.get('dest_dir')) + '/'
    os.makedirs(dest_dir, exist_ok=True)

    imgs = sorted([f'{imgs_dir}{img}' for img in os.listdir(imgs_dir)])
    img_path = imgs[-2]
    name = dest_dir + img_path.split('/')[-1].split('.')[0]
    img = cv.imread(img_path, cv.IMREAD_GRAYSCALE)

    thresh = 125

    dic = {}
    for i in range(6):
        dic[i] = {}
        dic[i]['Name'] = None
        dic[i]['Type'] = None
        dic[i]['Image'] = None
        dic[i]['Hist'] = None
        dic[i]['Save_name'] = None
    dic[0]['Name'] = 'Original'
    dic[1]['Name'] = 'Binary'
    dic[1]['Type'] = 0
    dic[2]['Name'] = 'Binary_Inverted'
    dic[2]['Type'] = 1
    dic[3]['Name'] = 'Threshold_Truncated'
    dic[3]['Type'] = 2
    dic[4]['Name'] = 'Threshold_to_Zero'
    dic[4]['Type'] = 3
    dic[5]['Name'] = 'Threshold_to_Zero_Inverted'
    dic[5]['Type'] = 4

    for i in range(6):
        if dic[i]['Type'] != None:
            _, dic[i]['Image'] = cv.threshold(img, thresh, 255, dic[i]['Type'])
            dic[i]['Save_name'] = name + dic[i]['Name'] + '.png'
        else:
            dic[i]['Image'] = img
            dic[i]['Save_name'] = name + '.png'
        dic[i]['Hist'] = cv.calcHist(dic[i]['Image'], [0], None, [256], [0, 256]).flatten()

    hists = []
    for i in range(6):
        hists.append(dic[i]['Hist'].max())
    max_y = max(hists)

    for i in range(6):
        plt.figure(figsize=(15,10))
        
        plt.subplot(1, 2, 1)
        plt.imshow(dic[i]['Image'], cmap='gray')
        plt.title(dic[i]['Name'])
        plt.axis('off')

        plt.subplot(1, 2, 2)
        plt.plot(dic[i]['Hist'], color='red', label='Histogram')
        plt.xlim(0, 256)
        plt.ylim(0, max_y)
        plt.title('Histogram')
        plt.xlabel('Gray Level')
        plt.ylabel('Pixel Count')
        plt.legend()
    
        plt.tight_layout()
        plt.savefig(dic[i]['Save_name'])

if __name__=="__main__":
    main()
