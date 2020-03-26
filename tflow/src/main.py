from __future__ import annotations
from typing import Callable

import numpy as np
import pandas as pd
import matplotlib.pyplot as plt

from pathlib import Path
from pprint import pprint
import tensorflow.compat.v2.feature_column as fc
import tensorflow as tf  # now import the tensorflow module


print(tf.version)  # make sure the version is 2.x
tf.keras.backend.set_floatx('float32')

images = Path(R'.\images')

string = tf.Variable("this is a string", tf.string)
number = tf.Variable(324, tf.int16)
floating = tf.Variable(3.567, tf.float64)

rank1_tensor = tf.Variable(["Test"], tf.string)
rank2_tensor = tf.Variable([["test", "ok"], ["test", "yes"]], tf.string)

print(tf.rank(rank2_tensor))


tensor1 = tf.ones([1, 2, 3])  # tf.ones() creates a shape [1,2,3] tensor full of ones
tensor2 = tf.reshape(tensor1, [2, 3, 1])  # reshape existing data to shape [2,3,1]
# -1 tells the tensor to calculate the size of the dimension in that place this will reshape the tensor to [3,3]
tensor3 = tf.reshape(tensor2, [3, -1])

print(tensor1)
print(tensor2)
print(tensor3)

# Load dataset.
dftrain = pd.read_csv('https://storage.googleapis.com/tf-datasets/titanic/train.csv')  # training data
dfeval = pd.read_csv('https://storage.googleapis.com/tf-datasets/titanic/eval.csv')  # testing data
y_train = dftrain.pop('survived')
y_eval = dfeval.pop('survived')

print(dftrain.head())
print(dftrain.describe())
print(dftrain.shape)

fig = plt.figure()

ax1 = fig.add_subplot(221)
ax1.hist(dftrain.age, bins=20)

ax2 = fig.add_subplot(222)
sex_count = dftrain.sex.value_counts()
labels = sex_count.index.values
ax2.bar(labels, sex_count)

ax3 = fig.add_subplot(223)
class_cnt = dftrain['class'].value_counts().sort_index()
ax3.plot(class_cnt)


ax4 = fig.add_subplot(224)
sex = pd.concat([dftrain, y_train], axis=1).groupby('sex').survived.mean()
labels = sex.index.values
ax4.set_xlabel('% survive')
ax4.barh(labels, sex)
# plt.show()
fig.savefig(images / 'titantic.png', dpi=fig.dpi)
plt.close()

CATEGORICAL_COLUMNS = ['sex', 'n_siblings_spouses', 'parch', 'class', 'deck', 'embark_town', 'alone']
NUMERIC_COLUMNS = ['age', 'fare']
feature_columns = []

for feature_name in CATEGORICAL_COLUMNS:
    vocabulary = dftrain[feature_name].unique()  # gets a list of all unique values from given feature column
    feature_columns.append(tf.feature_column.categorical_column_with_vocabulary_list(feature_name, vocabulary))

for feature_name in NUMERIC_COLUMNS:
    feature_columns.append(tf.feature_column.numeric_column(feature_name, dtype=tf.float64))

pprint(feature_columns)


def make_input_fn(data_df: pd.DataFrame,
                  label_df: pd.DataFrame,
                  num_epochs: int = 10,
                  shuffle: bool = True,
                  batch_size: int = 32,
                  ) -> Callable[[], tf.data.Dataset]:

    def input_function() -> tf.data.Dataset:  # inner function, this will be returned
        ds = tf.data.Dataset.from_tensor_slices((dict(data_df), label_df))  # create tf.data.Dataset object with data and its label
        if shuffle:
            ds = ds.shuffle(1000)  # randomize order of data
        ds = ds.batch(batch_size).repeat(num_epochs)  # split dataset into batches of 32 and repeat process for number of epochs
        return ds  # return a batch of the dataset

    return input_function  # return a function object for use


# here we will call the input_function that was returned to us to get a dataset object we can feed to the model
train_input_fn = make_input_fn(dftrain, y_train)
eval_input_fn = make_input_fn(dfeval, y_eval, num_epochs=10, shuffle=False)

# We create a linear estimtor by passing the feature columns we created earlier
linear_est = tf.estimator.LinearClassifier(feature_columns=feature_columns)
linear_est.train(train_input_fn)  # train
result = linear_est.evaluate(eval_input_fn)  # get model metrics/stats by testing on tetsing data

pprint(result)
print(result['accuracy'])  # the result variable is simply a dict of stats about our model

pred_dicts = list(linear_est.predict(eval_input_fn))
entry_index = 32
print(pred_dicts[entry_index]['probabilities'][1])  # chance to survive person 4
print(dfeval.loc[entry_index])  # data about person 4
print(y_eval.loc[entry_index])  # did person 4 actually survive? 1 = yes
probs = pd.Series([predict['probabilities'][1] for predict in pred_dicts])

fig2 = plt.figure()
# ax = fig2.add_subplot(111)
pred = probs.plot(kind='hist', bins=20, title='predicted probabilities')
fig2.axes.append(pred)
# plt.show()
fig2.savefig(images / 'prediction.png', dpi=fig.dpi)
plt.close()
