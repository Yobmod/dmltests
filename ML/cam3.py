"""."""
# import numpy as np
import matplotlib.pyplot as plt
import cv2

# from typing import # Tuple, Union  # , Any, NewType, TypeVar
from typing_extensions import Final
from mytypes import imageType

image: imageType = cv2.imread("./foo.png")
WIDTH: Final[int] = 300
HEIGHT: Final[int] = 300
print(image.shape)
# plt.imshow(image)


def grey_image(color_img: imageType) -> imageType:
    grey: imageType = cv2.cvtColor(color_img, cv2.COLOR_BGR2GRAY)
    plt.imshow(grey, cmap='gray')  # or cmap = gray_r / Greys / Greys_r
    return grey


def squash_image(origin_img: imageType, WIDTH: int = 300, HEIGHT: int = 300) -> imageType:
    """squash an image to given dimensions"""
    resized: imageType = cv2.resize(origin_img, (WIDTH, HEIGHT))
    plt.imshow(resized)
    return resized


def crop_center(origin_img: imageType, cropx: int = 300, cropy: int = 300) -> imageType:
    y, x, c = origin_img.shape
    startx = x // 2 - (cropx // 2)
    starty = y // 2 - (cropy // 2)
    cropped: imageType = origin_img[starty:starty + cropy, startx:startx + cropx]
    return cropped


def scale_image(origin_img: imageType, WIDTH: int = 300, HEIGHT: int = 300) -> imageType:
    """scale image to given dimensions, retaining landscape/portrait format"""
    aspect = origin_img.shape[1] / float(origin_img.shape[0])
    scaled: imageType
    # print(aspect)
    if(aspect > 1):
        # landscape orientation - wide image
        res = int(aspect * HEIGHT)
        scaled = cv2.resize(origin_img, (res, HEIGHT))
    if(aspect < 1):
        # portrait orientation - tall image
        res = int(WIDTH / aspect)
        scaled = cv2.resize(origin_img, (WIDTH, res))
    if(aspect == 1):
        scaled = cv2.resize(origin_img, (WIDTH, HEIGHT))

    plt.imshow(scaled)
    return scaled


def add_image_text(image: imageType, text: str) -> imageType:
    """add text to image """
    text_image = image.copy()
    text_font = cv2.FONT_HERSHEY_SIMPLEX
    text_origin_pos = (170, 30)  # from topleft
    text_scale = 0.8
    text_color = (20, 240, 150)
    text_line_thick = 2
    cv2.putText(text_image, text, text_origin_pos, text_font, text_scale, text_color, text_line_thick)

    under_start_offset = (-5, 10)  # -x to the left, y underneath
    line_length = 155
    under_start_pos = tuple(x + y for x, y in zip(text_origin_pos, under_start_offset))
    under_finish_pos = tuple(x + y for x, y in zip(under_start_pos, (line_length, 0)))
    under_color = (50, 100, 250)
    under_line_thick = 3
    cv2.line(text_image, under_start_pos, under_finish_pos, under_color, under_line_thick)

    plt.imshow(text_image)
    return text_image


edited_image = add_image_text(image, "added text!")
plt.imshow(edited_image)
# plt.savefig('foo.png')
plt.show()  # shows the last plt.imshow in window
