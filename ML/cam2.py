"""."""
import numpy as np
import matplotlib.pyplot as plt

# from typing import Tuple, Union  # , Any, NewType, TypeVar


color_1 = [255, 0, 0]      # red
color_2 = [0, 255, 0]      # green
color_3 = [0, 0, 255]      # blue
color_4 = [255, 255, 0]  # grey
color_list = [
    [
        color_3,  # blue
        color_2  # green
    ],
    [
        color_1,  # red
        color_4  # yellow
    ]
]
color_array = np.array(color_list)
print(color_array.shape)

plt.imshow(color_list)

start_row = 0
for row in color_list:
    start_col = -0.25
    for color in row:
        plt.text(start_col, start_row, str(color))
        start_col += 1
    start_row += 1

plt.savefig('foo.png')
plt.show()
