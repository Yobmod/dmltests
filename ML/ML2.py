from keras import preprocessing
from PIL import Image
import matplotlib.pyplot as plt
import numpy as np
import cv2

from keras.applications import inception_v3

model = inception_v3.InceptionV3(weights='imagenet')

model.summary()


image = Image.open('./data/phone.jpg')

plt.imshow(image)


img = preprocessing.image.load_img('./data/phone.jpg', target_size=(299, 299))
x = preprocessing.image.img_to_array(img)
x: np.ndarray[imageType] = np.expand_dims(x, axis=0)
x = inception_v3.preprocess_input(x)
predictions = model.predict(x)
labels = inception_v3.decode_predictions(predictions, top=3)[0]
