from dataclasses import dataclass
from flask import Flask
from PIL.Image import Image  # type: ignore
from typing import Type

app = Flask()

class n(Image): ...

@dataclass
class A():
    x: int
    y: str


a = A(1, "str")

b: 'Image' = Image("str") 

reveal_type(b)
