from typing import Tuple, Union, List  # , NewType  # , Any, NewType, TypeVar TYPE_CHECKING,

import numpy as np


# imageType = NewType('imageType', np._ArrayLike[np.ndarray[np.ndarray[int]]])
imageType = np._ArrayLike[np.ndarray[np.ndarray[int]]]
colorType = Union[List[int], Tuple[int, int, int, int], Tuple[int, int, int]]
