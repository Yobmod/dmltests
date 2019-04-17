# import time
import keras.models
from keras.optimizers import Adam
from keras.layers.convolutional import Convolution2D, MaxPooling2D
from keras.layers.core import Dropout, Flatten, Dense  # Activation,
from keras.models import Sequential
from keras.utils import to_categorical
import os
import random
from glob import glob
import cv2
import numpy as np
import matplotlib.pyplot as plt
from keras import preprocessing

from typing import List, cast
from mytypes import imageType

class_names: List[str] = ['BANANA', 'RED APPLE', 'PEAR', 'GREEN APPLE']


# get the reference to the webcam
camera = cv2.VideoCapture(0)
camera_height = 500
raw_frames_type_1 = []
raw_frames_type_2 = []
raw_frames_type_3 = []
raw_frames_type_4 = []

while(True):
    # read a new frame
    _, frame = camera.read()

    # flip the frame
    frame = cv2.flip(frame, 1)

    # rescaling camera output
    aspect = frame.shape[1] / float(frame.shape[0])
    res = int(aspect * camera_height)  # landscape orientation - wide image
    frame = cv2.resize(frame, (res, camera_height))

    # add rectangle
    cv2.rectangle(frame, (300, 75), (650, 425), (0, 255, 0), 2)

    # show the frame
    cv2.imshow("Capturing frames", frame)

    key = cv2.waitKey(1)

    # quit camera if 'q' key is pressed
    if key & 0xFF == ord("q"):
        break
    elif key & 0xFF == ord("1"):
        # save the frame
        raw_frames_type_1.append(frame)
        print('1 key pressed - saved TYPE_1 frame')
    elif key & 0xFF == ord("2"):
        # save the frame
        raw_frames_type_2.append(frame)
        print('2 key pressed - Saved TYPE_2 frame')
    elif key & 0xFF == ord("3"):
        # save the frame
        raw_frames_type_3.append(frame)
        print('3 key pressed - Saved TYPE_3 frame')
    elif key & 0xFF == ord("4"):
        # save the frame
        raw_frames_type_4.append(frame)
        print('4 key pressed - Saved TYPE_4 frame')

camera.release()
cv2.destroyAllWindows()


save_width = 399
save_height = 399

for i in range(1, 5):
    name = './data/images_type_{}'.format(i)
    os.makedirs(name, exist_ok=True)

for i, frame in enumerate(raw_frames_type_1):
    roi = frame[75 + 2:425 - 2, 300 + 2:650 - 2]
    roi = cv2.cvtColor(roi, cv2.COLOR_BGR2RGB)
    roi = cv2.resize(roi, (save_width, save_height))
    cv2.imwrite('./data/images_type_1/{}.png'.format(i), cv2.cvtColor(roi, cv2.COLOR_BGR2RGB))

for i, frame in enumerate(raw_frames_type_2):
    roi = frame[75 + 2:425 - 2, 300 + 2:650 - 2]
    roi = cv2.cvtColor(roi, cv2.COLOR_BGR2RGB)
    roi = cv2.resize(roi, (save_width, save_height))
    cv2.imwrite('./data/images_type_2/{}.png'.format(i), cv2.cvtColor(roi, cv2.COLOR_BGR2RGB))

for i, frame in enumerate(raw_frames_type_3):
    roi = frame[75 + 2:425 - 2, 300 + 2:650 - 2]
    roi = cv2.cvtColor(roi, cv2.COLOR_BGR2RGB)
    roi = cv2.resize(roi, (save_width, save_height))
    cv2.imwrite('./data/images_type_3/{}.png'.format(i), cv2.cvtColor(roi, cv2.COLOR_BGR2RGB))

for i, frame in enumerate(raw_frames_type_4):
    roi = frame[75 + 2:425 - 2, 300 + 2:650 - 2]
    roi = cv2.cvtColor(roi, cv2.COLOR_BGR2RGB)
    roi = cv2.resize(roi, (save_width, save_height))
    cv2.imwrite('./data/images_type_4/{}.png'.format(i), cv2.cvtColor(roi, cv2.COLOR_BGR2RGB))


width = 96
height = 96


def load_images(base_path: str) -> List[imageType]:
    images: List[imageType] = []
    path = os.path.join(base_path, '*.png')
    for image_path in glob(path):
        image = preprocessing.image.load_img(image_path,
                                             target_size=(width, height))
        x = preprocessing.image.img_to_array(image)

        images.append(x)
    return images


def check_images(image_set: int) -> None:
    plt.figure(figsize=(12, 8))

    images = load_images(f'./data/images_type_{image_set}')
    images_num = image_set - 1

    for i in range(5):
        plt.subplot(1, 5, i + 1)
        image = preprocessing.image.array_to_img(random.choice(images))
        plt.imshow(image)

        plt.axis('off')
        plt.title('{} image'.format(class_names[images_num]))
    # show the plot
    plt.show()


def image_list_to_array(image_set: int) -> np.ndarray[imageType]:
    images = load_images(f'./data/images_type_{image_set}')
    image_array = np.array(images)
    # print(image_array.shape)
    return image_array


check_images(1)
check_images(2)
image_array_1 = image_list_to_array(1)
image_array_2 = image_list_to_array(2)
image_array_3 = image_list_to_array(3)
image_array_4 = image_list_to_array(4)

image_training_array = np.concatenate((image_array_1, image_array_2, image_array_3, image_array_4), axis=0) / 255


y_type_1 = [0 for item in enumerate(image_array_1)]
y_type_2 = [1 for item in enumerate(image_array_2)]
y_type_3 = [2 for item in enumerate(image_array_3)]
y_type_4 = [3 for item in enumerate(image_array_4)]

y = np.concatenate((y_type_1, y_type_2, y_type_3, y_type_4), axis=0)

y = to_categorical(y, num_classes=len(class_names))

print(y.shape)


# default parameters
conv_1 = 16
conv_1_drop = 0.2
conv_2 = 32
conv_2_drop = 0.2
dense_1_n = 1024
dense_1_drop = 0.2
dense_2_n = 512
dense_2_drop = 0.2
lr = 0.001

epochs = 30
batch_size = 32
color_channels = 3


def build_model(conv_1_drop: float, conv_2_drop: float,
                dense_1_n: int, dense_1_drop: float,
                dense_2_n: int, dense_2_drop: float,
                lr: float) -> keras.models.Sequential:

    model = Sequential()

    model.add(Convolution2D(conv_1, (3, 3),
                            input_shape=(width, height, color_channels),
                            activation='relu'))

    model.add(MaxPooling2D(pool_size=(2, 2)))
    model.add(Dropout(conv_1_drop))

    model.add(Convolution2D(conv_2, (3, 3), activation='relu'))
    model.add(MaxPooling2D(pool_size=(2, 2)))
    model.add(Dropout(conv_2_drop))

    model.add(Flatten())

    model.add(Dense(dense_1_n, activation='relu'))
    model.add(Dropout(dense_1_drop))

    model.add(Dense(dense_2_n, activation='relu'))
    model.add(Dropout(dense_2_drop))

    model.add(Dense(len(class_names), activation='softmax'))

    model.compile(loss='categorical_crossentropy',
                  optimizer=Adam(lr=lr),
                  metrics=['accuracy'])

    return model


np.random.seed(1)  # for reproducibility

# model with base parameters
model = build_model(conv_1_drop=conv_1_drop, conv_2_drop=conv_2_drop,
                    dense_1_n=dense_1_n, dense_1_drop=dense_1_drop,
                    dense_2_n=dense_2_n, dense_2_drop=dense_2_drop,
                    lr=lr)

model.summary()
model.save('fruit_cnn_model.h5')
# model = load_model('fruit_cnn_model.h5')

type_1 = preprocessing.image.load_img('./data/images_type_1/0.png',
                                      target_size=(width, height))
plt.imshow(type_1)
plt.show()

type_1_X = np.expand_dims(type_1, axis=0)

"""
predictions: List[float] = list(model.predict(type_1_X))  # array of relative likelyhoods. Cast to list for mypy
predicted_index: int = np.argmax(predictions)  # return index of most likely
# if predicted_index < len(class_names) - 1:
predicted_name: str = class_names[predicted_index]
"""

predictions: np.ndarray[float] = model.predict(type_1_X)  # array of relative likelyhoods.
predicted_index: int = cast(int, predictions.argmax().item(0))  # return index array of most likely. Get first (only) item
predicted_name: str = class_names[predicted_index]

print('The type predicted is: {}'.format(predicted_name))


type_2 = preprocessing.image.load_img('./data/images_type_2/8.png',
                                      target_size=(width, height))
plt.imshow(type_2)
plt.show()

type_2_X = np.expand_dims(type_2, axis=0)

predictions = model.predict(type_2_X)

print('The type predicted is: {}'.format(class_names[cast(int, np.argmax(predictions))]))


# get the reference to the webcam
camera = cv2.VideoCapture(0)
camera_height = 500

while(True):
    # read a new frame
    _, frame = camera.read()

    # flip the frameq
    frame = cv2.flip(frame, 1)

    # rescaling camera output
    aspect = frame.shape[1] / float(frame.shape[0])
    res = int(aspect * camera_height)  # landscape orientation - wide image
    frame = cv2.resize(frame, (res, camera_height))

    # add rectangle
    cv2.rectangle(frame, (300, 75), (650, 425), (240, 100, 0), 2)

    # get ROI
    roi = frame[75 + 2:425 - 2, 300 + 2:650 - 2]

    # parse BRG to RGB
    roi = cv2.cvtColor(roi, cv2.COLOR_BGR2RGB)

    # resize
    roi = cv2.resize(roi, (width, height))

    # predict!
    roi_X = np.expand_dims(roi, axis=0)

    predictions = model.predict(roi_X)
    type_1_pred, type_2_pred, type_3_pred, type_4_pred = predictions[0]

    # add text
    type_1_text = '{}: {}%'.format(class_names[0], int(type_1_pred * 100))
    cv2.putText(frame, type_1_text, (70, 170),
                cv2.FONT_HERSHEY_SIMPLEX, 0.6, (240, 240, 240), 2)

    # add text
    tipe_2_text = '{}: {}%'.format(class_names[1], int(type_2_pred * 100))
    cv2.putText(frame, tipe_2_text, (70, 200),
                cv2.FONT_HERSHEY_SIMPLEX, 0.6, (240, 240, 240), 2)

    # add text
    tipe_3_text = '{}: {}%'.format(class_names[2], int(type_3_pred * 100))
    cv2.putText(frame, tipe_3_text, (70, 230),
                cv2.FONT_HERSHEY_SIMPLEX, 0.6, (240, 240, 240), 2)

    # add text
    tipe_4_text = '{}: {}%'.format(class_names[3], int(type_4_pred * 100))
    cv2.putText(frame, tipe_4_text, (70, 260),
                cv2.FONT_HERSHEY_SIMPLEX, 0.6, (240, 240, 240), 2)

    # show the frame
    cv2.imshow("Test out", frame)

    key = cv2.waitKey(1)

    # quit camera if 'q' key is pressed
    if key & 0xFF == ord("q"):
        break

camera.release()
cv2.destroyAllWindows()
