"""."""

import cv2
import imutils
import argparse
import numpy as np
from pathlib import Path


from typing import List  # Union  # , Any, NewType, TypeVar
from mytypes import imageType

DEBUG = True

IMAGES: List[imageType] = []

def main():
    # construct the argument parse and parse the arguments
    ap = argparse.ArgumentParser()
    ap.add_argument("-i", "--image",
                    type=lambda p: Path(p).absolute(),  # function used to coerce the input string to
                    default=R".\shapes.png",  # used if not -i or --image
                    nargs="?",  # number of args is 0 or 1
                    const=R".\shapes.png",  # used if -i or --image but not value given, if nargs="?"
                    help="path to the image file"
                    )
    args = vars(ap.parse_args())  # dictionary of args: objects  e.g. {"image": xxx.png}


    # load the image, check name is valid image file
    image_path = args["image"]
    image: imageType = cv2.imread(str(image_path))

    if image is not None:
        print(f"Image loaded from {image_path}")
        IMAGES.append(image)
    else:
        # print(f"Failed to load image from {image_path}")
        raise ValueError(f"Failed to load image from {image_path}")
        # stops the script is filename error

    # find all the 'black' shapes in the image
    lower = np.array([0, 0, 0])  # black
    upper = np.array([15, 15, 15])  # dark grey
    shapeMask = cv2.inRange(image, lower, upper)
    IMAGES.append(shapeMask)

    # find the contours in the mask
    cnts = cv2.findContours(shapeMask.copy(), cv2.RETR_EXTERNAL, cv2.CHAIN_APPROX_SIMPLE)
    cnts = imutils.grab_contours(cnts)
    print("I found {} black shapes".format(len(cnts)))
    cv2.imshow("Mask", shapeMask)

    image_outlined = image.copy()
    for c in cnts:
        # outline the contour in green and show it
        cv2.drawContours(image_outlined, [c], -1, (0, 255, 0), 2)
    IMAGES.append(image_outlined)

    cv2.imshow("Image", image_outlined)
    cv2.waitKey(0)


    if DEBUG is True:
        print(vars())

if __name__ == "__main__":
    main()