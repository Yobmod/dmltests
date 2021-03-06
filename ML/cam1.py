"""."""
from datetime import datetime
import cv2
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


cap = cv2.VideoCapture(0)

if cap.isOpened() is True:
    print("initialising camera")
else:
    print("no camera found")
    cap = cv2.VideoCapture(1)

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


def save_image_groups(frames_list: List[imageType]) -> None:
    # print(frames_list)
    today = datetime.today().strftime('%Y_%m_%d')
    now = datetime.now().strftime('%H%M%S')

    for index, frame in enumerate(frames_list):
        # create folder with index number
        name = pathlib.Path(f'./data/frames/images_{today}')
        name.mkdir(parents=True, exist_ok=True)
        # save images to folders
        cv2.imwrite(f'{name}/{index}_raw_{now}.png', cv2.cvtColor(frame, cv2.COLOR_BGR2RGB))


save_image_groups(raw_frames)
