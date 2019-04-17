from keras import preprocessing
from PIL import Image
import matplotlib.pyplot as plt
import numpy as np
# import cv2
from keras.applications import inception_v3

from mytypes import imageType

model = inception_v3.InceptionV3(weights='imagenet')

model.summary()


image = Image.open('./data/phone.jpg')

plt.imshow(image)


img = preprocessing.image.load_img('./data/phone.jpg', target_size=(299, 299))
img_array = preprocessing.image.img_to_array(img)
image_exp_array: np.ndarray[imageType] = np.expand_dims(img_array, axis=0)
image_incept = inception_v3.preprocess_input(image_exp_array)
predictions = model.predict(image_incept)
labels = inception_v3.decode_predictions(predictions, top=3)[0]

print(labels)  # weighted array of guesses
