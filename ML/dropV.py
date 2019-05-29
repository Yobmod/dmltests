"""scripts to preocess droplet video file, saving video output and csv of relavent data (frame_no, time, angle, height, width)
Required modules: dmlutils / mytypes 
Dependencies: CV2, numpy, Pillow"""
# -*- coding: utf-8 -*-
import cv2
# from PIL import Image, ImageFont, ImageDraw
from pathlib import Path
import numpy as np

from dmlutils import get_outlined_image, crop_outlined_image, get_contour_lims, calc_contact_angle, save_image_groups  # set_res

from typing import List, Tuple
from mytypes import videoType, imageType, floatArray  # , colorType, PILImage


video_title = R'.test.avi'
video_path = Path(video_title).absolute()  # .resolve()  ?
video_stem = video_path.stem  # .anchor (.drive .root) .parent .name (.stem .suffix)

if video_path.exists():
    vid: videoType = cv2.VideoCapture(video_title)
else:
    print("Error: Video file not found...")

fps: int = vid.get(cv2.CAP_PROP_FPS)      # OpenCV2 version 2 used "CV_CAP_PROP_FPS"
frameCount = int(vid.get(cv2.CAP_PROP_FRAME_COUNT))
duration = frameCount / fps  # seconds

# Define the codec and create VideoWriter object
fourcc = cv2.VideoWriter_fourcc(*'XVID')
masked_vid: videoType = cv2.VideoWriter('output.avi', fourcc, 20.0, (640, 480))

raw_frames: List[imageType] = []
edged_frames: List[imageType] = []
masked_frames: List[imageType] = []
CA_list: List[float] = []
CA_array: floatArray = np.zeros(len(vid))


while vid.isOpened():  # and img.any():

    frame_out: Tuple[bool, imageType] = vid.read()
    # (ret, frame) = frame_out  ## loses typings :/
    ret = frame_out[0]
    frame = frame_out[1]

    if ret is True:

        frame_no = 0

        cv2.imshow('image window', frame)
        raw_frames.append(frame)

        """
        gray: imageType = cv2.cvtColor(frame, cv2.COLOR_BGR2GRAY)
        blurred: imageType = cv2.GaussianBlur(frame, (3, 3), 0)
        edged: imageType = cv2.Canny(gray, 20, 100)
        edged_frames.append(edged)
        """

        edged: imageType = get_outlined_image(frame)
        edged_frames.append(edged)

        masked: imageType = crop_outlined_image(edged)
        masked_frames.append(masked) 
        masked_vid.write(masked)

        (x, y, w, h) = get_contour_lims(edged)
        ang = calc_contact_angle(w, h)
        CA_list.append(ang)
        CA_array[frame_no] = calc_contact_angle(w, h)
        vid_time = duration / frame_no
        #CA_array[frame_no, 0] = ang
        #CA_array[frame_no, 1] = w
        #CA_array[frame_no, 2] = h
        frame_no += 1


        key: int = cv2.waitKey(0) & 0xFF

        if key & 0xFF == ord("q"):  # quit camera if 'q' key is pressed
            break
        elif key & 0xFF == ord("s"):
            print('S key pressed - saved frame')  # save the frame
    else:
        break  # break if problem with a frame

else:
    print("Error: Video not opened...")

vid.release()
masked_vid.release()
cv2.destroyAllWindows()

# save raw, edged, masked
save_image_groups(raw_frames)

# save angles, time (h and w?)
# csv.writer (or numpy array to csv?)
out_folder_path = Path(video_path / "out")
out_folder_path.mkdir(exist_ok=True)

out_file_path: Path = out_folder_path / video_stem / ".csv"
out_file = out_file_path.resolve()

# np.savetxt(out_file, CA_array, delimiter=",")  # np required by cv2, so may as well use it
