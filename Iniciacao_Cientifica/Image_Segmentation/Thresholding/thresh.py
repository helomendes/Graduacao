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

    dic = {}
    for i in range(6):
        dic[i] = {}
        dic[i]['Name'] = None
        dic[i]['Type'] = None
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
            _, dst = cv.threshold(img, 100, 255, dic[i]['Type'])
            save_name = name + dic[i]['Name'] + '.jpg'
        else:
            dst = img
            save_name = name + '.jpg'
        hist = cv.calcHist(dst, [0], None, [256], [0, 256]).flatten()

        plt.figure(figsize=(15,10))
        
        plt.subplot(1, 2, 1)
        plt.imshow(dst, cmap='gray')
        plt.title(dic[i]['Name'])
        plt.axis('off')

        plt.subplot(1, 2, 2)
        plt.plot(hist, color='black', label='Histogram')
        plt.title('Histogram')
        plt.xlabel('Gray Level')
        plt.ylabel('Pixel Count')
        plt.legend()
    
        plt.tight_layout()
        plt.savefig(save_name)

if __name__=="__main__":
    main()
