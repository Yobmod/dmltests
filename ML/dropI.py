"""."""
# -*- coding: utf-8 -*-
import cv2

from dmlutils import add_image_text, get_outlined_image, crop_outlined_image, save_image_groups, find_x_extremes  # set_res

import typing as t
from mytypes import imageType


# raw_frames: t.List[imageType] = []

img: imageType = cv2.imread(R'.\data\test.jpg', cv2.IMREAD_COLOR)  # cv2.IMREAD_GRAYSCALE  /  cv2.IMREAD_UNCHANGED

while True:
    cv2.imshow('test image', img)

    key = cv2.waitKey(0) & 0xFF

    if key == ord('s'):  # wait for 's' key to save and exit
        edged = get_outlined_image(img)
        mask = crop_outlined_image(edged)
        ang = find_x_extremes(edged)
        annotated = add_image_text(mask, f"C. angle = {ang:.1f}")
        cv2.imwrite(R'.\data\test_edged.png', edged)
        cv2.imwrite(R'.\data\test_masked.png', mask)
        cv2.imwrite(R'.\data\test_annotated.png', annotated)


    elif key == 27 or key == ord("q"):         # wait for ESC key or Q to exit
        break
        
cv2.destroyAllWindows()

    # gray: np.ndarray = cv2.cvtColor(frame, cv2.COLOR_BGR2GRAY)
    # 0=vert, 1=horiz, -1=both       # Display the resulting frame
    # vflipped: imageType = cv2.flip(frame, 0)
    # 0=vert, 1=horiz, -1=both       # Display the resulting frame
    # hflipped: imageType = cv2.flip(frame, 1)

    # blurred = cv2.GaussianBlur(frame, (3, 3), 0)
    # # edged = cv2.Canny(gray, 20, 100)
"""
save_image_groups(raw_frames)
"""
