from typing import TYPE_CHECKING, Tuple, Union, List  # , Any, NewType, TypeVar

import numpy as np


if TYPE_CHECKING:  # for mypy
    imageType = np._ArrayLike[np.ndarray[np.ndarray[int]]]
else:  # python doesnt allow ndarray subscriptable yet
    imageType = np.ndarray


colorType = Union[List[int], Tuple[int, int, int, int], Tuple[int, int, int]]
