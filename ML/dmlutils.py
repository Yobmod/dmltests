"""."""
# -*- coding: utf-8 -*-
from datetime import datetime
import numpy as np
import cv2
import math
# import imutils
import pathlib

from typing import Tuple, Union, List  # , Any, NewType, TypeVar
from mytypes import imageType


def set_res(cap: cv2.VideoCapture, resolution: Union[int, str]) -> str:
    """."""
    if resolution in [480, "480", "480p"]:
        cap.set(3, 640)
        cap.set(4, 480)
    elif resolution in [1080, "1080", "1080p"]:
        cap.set(3, 1920)
        cap.set(4, 1080)
    elif resolution in [720, "720", "720p"]:
        cap.set(3, 1920)
        cap.set(4, 1080)
    else:
        resolution = 720
        set_res(cap, resolution)
    return str(resolution)


def get_outlined_image(frame: imageType) -> imageType:
    grayed: imageType = cv2.cvtColor(frame, cv2.COLOR_BGR2GRAY)
    blurred: imageType = cv2.GaussianBlur(grayed, (9, 9), 0)
    # perform edge detection, then perform a dilation + erosion to close gaps
    edged: imageType = cv2.Canny(blurred, 20, 100)
    edged = cv2.dilate(edged, None, iterations=1)
    edged = cv2.erode(edged, None, iterations=1)
    return edged


def find_x_extremes(frame: imageType) -> float:
    "get left and right most pixels in edged image"
    result: Tuple[List[np.ndarray[float]], List[List[np.ndarray[int]]]]
    result = cv2.findContours(frame.copy(), cv2.RETR_EXTERNAL, cv2.CHAIN_APPROX_SIMPLE)
    contours = result[0]
    if len(contours) > 0:
        # grab the largest contour, then draw a mask for the pill
        # cnt_areas = [cv2.contourArea(cntr) for cntr in contours]
        # c = max(cnt_areas)
        largest_contour = max(contours, key=cv2.contourArea)
        (x, y, w, h) = cv2.boundingRect(largest_contour)
        print((x, y, w, h))

        drop_h = h / 2
        radius = (drop_h / 2) + (w * w / 8 * h)
        opp = radius - drop_h
        hyp = radius
        sin_ca = opp / hyp
        ca = math.degrees(math.asin(sin_ca))
        print(ca)

        opp = h / 2
        ajd = w / 2
        tan_angle = opp / ajd
        angle = math.degrees(math.atan(tan_angle))
    else:
        raise ValueError("No contours identified in image")
    return angle


def crop_outlined_image(frame: imageType) -> imageType:
    """find contours in an edged image, create a mask sized to largest contour and apply to image"""
    # contours = imutils.grab_contours(resul
    result: Tuple[List[np.ndarray[float]], List[List[np.ndarray[int]]]]
    result = cv2.findContours(frame.copy(), cv2.RETR_EXTERNAL, cv2.CHAIN_APPROX_SIMPLE)
    contours = result[0]

    # ensure at least one contour was found
    if len(contours) > 0:
        # grab the largest contour, then draw a mask for the pill
        # cnt_areas = [cv2.contourArea(cntr) for cntr in contours]
        # c = max(cnt_areas)
        largest_contour = max(contours, key=cv2.contourArea)
        mask = np.zeros(frame.shape, dtype=np.uint8)
        cv2.drawContours(mask, [largest_contour], -1, 255, -1)  # mask, ?, opacity?, -1 = filled in

        # compute its bounding box of pill, then extract the ROI,
        # and apply the mask
        (x, y, w, h) = cv2.boundingRect(largest_contour)
        imageROI: imageType = frame[y:y + h, x:x + w]
        maskROI = mask[y:y + h, x:x + w]
        imageROI = cv2.bitwise_and(imageROI, imageROI, mask=maskROI)
        return imageROI
    else:
        raise ValueError("No contours identified in image")


def save_image_groups(frames_list: List[imageType], save_folder: str = "data", raw: bool = True, edged: bool = False, masked: bool = False) -> None:
    # print(frames_list)
    today = datetime.today().strftime('%Y_%m_%d')
    now = datetime.now().strftime('%H%M%S')
    name = pathlib.Path(f'./{save_folder}/images_{today}')
    name.mkdir(parents=True, exist_ok=True)

    if raw is True:
        for index, frame in enumerate(frames_list):
            cv2.imwrite(f'{name}/{index}_raw_{now}.png', cv2.cvtColor(frame, cv2.COLOR_BGR2RGB))

    if edged is True or masked is True:
        edged_frames: List[imageType] = [get_outlined_image(frame) for frame in frames_list]

        if edged is True:
            for index, frame in enumerate(edged_frames):
                cv2.imwrite(f'{name}/{index}_edged_{now}.png', frame)

        if masked is True:
            masked_frames: List[imageType] = [crop_outlined_image(frame) for frame in edged_frames]
            for index, frame in enumerate(masked_frames):
                cv2.imwrite(f'{name}/{index}_mask_{now}.png', frame)


def add_image_text(image: imageType, text: str, underline: bool = False) -> imageType:
    """add text to image """

    text_image = cv2.cvtColor(image.copy(), cv2.COLOR_GRAY2RGB)
    h, w = text_image.shape[:2]
    text_font = cv2.FONT_HERSHEY_SIMPLEX
    text_origin_pos = (int(w/10), int(9*h/10))  # from topleft
    text_scale = 0.4
    text_color = (154, 205, 50)
    text_line_thick = 1
    cv2.putText(text_image, text, text_origin_pos, text_font, text_scale, text_color, text_line_thick, lineType=cv2.LINE_AA)

    if underline:
        under_start_offset = (-5, 10)  # -x to the left, y underneath
        line_length = 155
        under_start_pos = tuple(x + y for x, y in zip(text_origin_pos, under_start_offset))
        under_finish_pos = tuple(x + y for x, y in zip(under_start_pos, (line_length, 0)))
        under_color = (50, 100, 250)
        under_line_thick = 2
        cv2.line(text_image, under_start_pos, under_finish_pos, under_color, under_line_thick)

    return text_image
