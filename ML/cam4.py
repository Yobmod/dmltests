"""."""
# import numpy as np
import matplotlib.pyplot as plt
import cv2

from typing import Tuple, List  # Union  # , Any, NewType, TypeVar
# from typing_extensions import Final
from mytypes import imageType


CAMERA = cv2.VideoCapture(0)
HEIGHT = 500
RAW_FRAMES: List[imageType] = []
IMAGES: List[imageType] = []
print("Attach campera. S to save images, Q to quit")

while(CAMERA.isOpened()):

    # read a new frame
    frame_out: Tuple[bool, imageType] = CAMERA.read()
    ret = frame_out[0]
    frame = frame_out[1]
    # reveal_locals()

    if ret is True:
        frame = cv2.flip(frame, 1)

        # rescaling camera output
        aspect: float = frame.shape[1] / float(frame.shape[0])
        res = int(aspect * HEIGHT)  # landscape orientation - wide image
        frame = cv2.resize(frame, (res, HEIGHT))

        # draw reticle
        cv2.rectangle(frame, (300, 75), (650, 425), (0, 255, 0), 2)
        # show the frame
        cv2.imshow("Capturing frames", frame)

    # quit camera if 'q' key is pressed
    key = cv2.waitKey(1)
    if key & 0xFF == ord("q"):
        break
    elif key & 0xFF == ord("s"):
        # save the frame
        RAW_FRAMES.append(frame)

        # preview the frame
        plt.imshow(frame)
        plt.show()

CAMERA.release()
cv2.destroyAllWindows()


for frame in RAW_FRAMES:
    # get ROI within reticle
    roi: imageType = frame[75 + 1:425 - 1, 300 + 1:650 - 1]

    # parse BRG to RGB
    roi = cv2.cvtColor(roi, cv2.COLOR_BGR2RGB)

    IMAGES.append(roi)
    print(f"{len(IMAGES)} images captured and processed")
    plt.imshow(roi)
    plt.show()
