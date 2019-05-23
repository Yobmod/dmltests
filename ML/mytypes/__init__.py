from typing import Type, TYPE_CHECKING, Tuple, Union, List  # , Any, NewType, TypeVar
from PIL import Image
import numpy as np


if TYPE_CHECKING:  # for mypy
    imageType = np._ArrayLike[np.ndarray[np.ndarray[int]]]
    contourType = np._ArrayLike[np.ndarray[np.ndarray[int]]]
else:  # python doesnt allow ndarray subscriptable yet
    imageType = np.ndarray
    contourType = np.ndarray


class PILImage(Image.Image): ...


colorType = Union[Tuple[int, int, int, int], Tuple[int, int, int]]
pointType = Tuple[int, int]
