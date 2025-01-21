import os
import yaml
import argparse
import skimage as ski
import matplotlib.pyplot as plt
from skimage import morphology
from scipy import ndimage as ndi
from skimage.feature import canny
from skimage.exposure import histogram

def main():
    parse = argparse.ArgumentParser()
    parse.add_argument('--config')
    parse.add_argument('-c', required=False, action='store_true')
    args = parse.parse_args()

    with open(args.config, 'r') as file:
        config = yaml.safe_load(file)

    dest = os.path.abspath(config.get('dest_dir')) + '/'
    os.makedirs(dest, exist_ok=True)

    if args.c:
        name = 'coins'
        img = ski.data.coins()
    else:
        img_path = config.get('img')
        name = img_path.split('/')[-1][:-3]
        img = ski.io.imread(img_path, as_gray = True)
        img = ski.util.img_as_ubyte(img)

    hist, hist_centers = ski.exposure.histogram(img)

    fig, axs = plt.subplots(2, 2, figsize = (10, 5))
    
    low = 100
    high = 150
    axs[0][0].imshow(img, cmap='gray')
    axs[0][0].set_title('')
    axs[0][0].axis('off')
    axs[0][1].plot(hist_centers, hist, lw=2)
    axs[0][1].set_title('histograms of gray values')
    axs[1][0].imshow(img > low, cmap = plt.cm.gray)
    axs[1][0].set_title(f'img > {low}')
    axs[1][0].set_axis_off()
    axs[1][1].imshow(img > high, cmap = plt.cm.gray)
    axs[1][1].set_title(f'img > {high}')
    axs[1][1].set_axis_off()
    fig.tight_layout()

    plt.savefig(f'{dest}thresholding_{name}_{low}_{high}.png')
    plt.show()

    edges = canny(img)
    fill = ndi.binary_fill_holes(edges)
    clean = morphology.remove_small_objects(fill, 21)

    fig, axs = plt.subplots(1, 3, figsize = (10, 5))
    axs[0].imshow(edges, cmap=plt.cm.gray)
    axs[0].set_title('Canny detector')
    axs[0].set_axis_off()
    axs[1].imshow(fill, cmap=plt.cm.gray)
    axs[1].set_title('Filled')
    axs[1].set_axis_off()
    axs[2].imshow(clean, cmap=plt.cm.gray)
    axs[2].set_title('Cleaned')
    axs[2].set_axis_off()
    fig.tight_layout()

    plt.savefig(f'{dest}segmentation_{name}.png')
    plt.show()

if __name__ == "__main__":
    main()
