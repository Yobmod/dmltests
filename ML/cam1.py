"""."""
from datetime import datetime
import numpy as np
import cv2
import imutils
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


cap = cv2.VideoCapture(0)

if cap is True:
    print("initialising camera")
else:
    print("no camera found")


set_res(cap, 480)
raw_frames = []

while(cap.isOpened()):
    frame_out: Tuple[bool, imageType] = cap.read()
    # (ret, frame) = frame_out  ## loses typings :/
    ret = frame_out[0]
    frame = frame_out[1]

    if ret is True:
        # Our operations on the frame come here
        # gray: np.ndarray = cv2.cvtColor(frame, cv2.COLOR_BGR2GRAY)
        # 0=vert, 1=horiz, -1=both       # Display the resulting frame
        vflipped: imageType = cv2.flip(frame, 0)
        # 0=vert, 1=horiz, -1=both       # Display the resulting frame
        hflipped: imageType = cv2.flip(frame, 1)

        # blurred = cv2.GaussianBlur(frame, (3, 3), 0)
        # # edged = cv2.Canny(gray, 20, 100)

        cv2.imshow('image window', frame)
        # cv2.imshow('frame1', gray)
        # cv2.imshow('frame2', vflipped)
        # cv2.imshow('frame2', hflipped)

        key = cv2.waitKey(1)  # wait 1 ms after each frame is shown to capture any input

    # quit camera if 'q' key is pressed
        if key & 0xFF == ord("q"):
            break
        elif key & 0xFF == ord("s"):
            # save the frame
            raw_frames.append(frame)
            print('S key pressed - saved frame')
    else:
        break


# When everything done, release the capture
cap.release()
cv2.destroyAllWindows()


def get_outlined_image(frame: imageType) -> imageType:
    grayed: imageType = cv2.cvtColor(frame, cv2.COLOR_BGR2GRAY)
    blurred: imageType = cv2.GaussianBlur(grayed, (3, 3), 0)
    # perform edge detection, then perform a dilation + erosion to close gaps
    edged: imageType = cv2.Canny(blurred, 20, 100)
    edged = cv2.dilate(edged, None, iterations=1)
    edged = cv2.erode(edged, None, iterations=1)
    return edged


def crop_outlined_image(frame: imageType) -> imageType:
    # find contours in the edge map
    cnts = cv2.findContours(frame.copy(), cv2.RETR_EXTERNAL, cv2.CHAIN_APPROX_SIMPLE)
    cnts = imutils.grab_contours(cnts)
    # ensure at least one contour was found
    if len(cnts) > 0:
        # grab the largest contour, then draw a mask for the pill
        c = max(cnts, key=cv2.contourArea)
        mask = np.zeros(frame.shape, dtype=np.uint8)
        cv2.drawContours(mask, [c], -1, 255, -1)  # mask, ?, opacity?, -1 = filled in

        # compute its bounding box of pill, then extract the ROI,
        # and apply the mask
        (x, y, w, h) = cv2.boundingRect(c)
        imageROI: imageType = frame[y:y + h, x:x + w]
        maskROI = mask[y:y + h, x:x + w]
        imageROI = cv2.bitwise_and(imageROI, imageROI, mask=maskROI)
        return imageROI
    else:
        raise AttributeError


def save_image_groups(frames_list: List[imageType]) -> None:
    edged_frames: List[imageType] = [get_outlined_image(frame) for frame in frames_list]
    masked_frames: List[imageType] = [crop_outlined_image(frame) for frame in frames_list]

    now = datetime.now().strftime('%Y%m%d_%H%M%S')

    for index, frame in enumerate(frames_list):
        # create folder with index number
        name = pathlib.Path(f'./data/images_{now}_{index}')
        name.mkdir(parents=True, exist_ok=True)
        # save images to folders
        cv2.imwrite(f'{name}/raw{index}.png', cv2.cvtColor(frame, cv2.COLOR_BGR2RGB))
        cv2.imwrite(f'{name}/edged{index}.png', edged_frames[index])
        cv2.imwrite(f'{name}/mask{index}.png', masked_frames[index])


save_image_groups(raw_frames)
