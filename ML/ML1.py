"""."""
# import numpy as np
import matplotlib.pyplot as plt
import cv2
from sklearn.cluster import KMeans
from collections import Counter

from typing import List  # Sequence  # , Union  # , Any, NewType, TypeVar
# from typing_extensions import Final
from mytypes import colorType, imageType


def rgb2hex(rgb: colorType, use_opacity: bool = True) -> str:
    """convert RGB(A) color as list or tuple to hex"""
    if len(rgb) == 3 or (len(rgb) == 4 and use_opacity is False):
        hex = "#{:02x}{:02x}{:02x}".format(int(rgb[0]), int(rgb[1]), int(rgb[2]))
    elif len(rgb) == 4 and use_opacity is True:
        hex = "#{:02x}{:02x}{:02x}{:02x}".format(int(rgb[0]), int(rgb[1]), int(rgb[2]), int(rgb[3]))
    else:
        if 3 < len(rgb) > 4:
            raise ValueError("""not a valid RGB(A) value""")
    return hex


def plot_image_info(path: str, k: int = 6) -> None:
    # load image
    img_bgr = cv2.imread(path)
    img_rgb = cv2.cvtColor(img_bgr, cv2.COLOR_BGR2RGB)

    # resize image to speed up processing time
    resized_img_rgb: imageType = cv2.resize(img_rgb, (64, 64), interpolation=cv2.INTER_AREA)

    # reshape the image to be a list of pixels
    img_list: List[int] = resized_img_rgb.reshape((resized_img_rgb.shape[0] * resized_img_rgb.shape[1], 3))

    # cluster the pixels and assign labels
    clt = KMeans(n_clusters=k)
    labels = clt.fit_predict(img_list)

    # count labels to find most popular
    label_counts = Counter(labels)
    # total_count = sum(label_counts.values())

    # subset out most popular centroid
    center_colors = list(clt.cluster_centers_)
    ordered_colors = [center_colors[i] / 255 for i in label_counts.keys()]
    color_labels = [rgb2hex(ordered_colors[i] * 255) for i in label_counts.keys()]

    # print(label_counts.values())
    # print(color_labels)

    # plots
    plt.figure(figsize=(14, 8))
    plt.subplot(221)
    plt.imshow(img_rgb)
    plt.axis('off')

    plt.subplot(222)
    plt.pie(label_counts.values(),
            labels=color_labels,
            colors=ordered_colors,
            startangle=90,
            wedgeprops={'edgecolor': 'black', 'linewidth': 1, 'linestyle': '-', 'antialiased': True}
            )
    plt.axis('equal')
    plt.show()


plot_image_info(R".\\foo.png", k=5)
