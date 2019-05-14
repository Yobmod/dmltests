import pytest

from typing import Any

from cam5 import IMAGES

def test1() -> None:
    a = "test"
    assert len(a) == 4



@pytest.mark.xfail
def test2() -> None:
    a = 111
    if not isinstance(a, str):
        pytest.fail("should be a string (supposed to fail!)")


def function_with_exception(inputt: str) -> Any:
    output = inputt + 5
    return output


def test3() -> None:
    with pytest.raises(TypeError) as e:
        function_with_exception("datainput")
        assert str(e.value) == 'can only concatenate str(not "int") to str'


def test_image_list() -> None:
    assert isinstance(IMAGES, list)
    if len(IMAGES) > 0:
        for image in IMAGES:
            assert len(image) > 1
""" Exception is raised if no image, 
but currently default image used so is never raised. Add tests to check if default image file is there, 
and another test for IMAGES raising exception if not there"""