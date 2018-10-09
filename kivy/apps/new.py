
from typing import Union, List, Optional as Opt, overload


@overload
def funct(strg: Union[str, List[str]]) -> str: ...

@overload
def funct(strg: int) -> int: ...

@overload
def funct(strg: None) -> None: ...

@overload
def funct() -> None: ...


def funct(strg: Opt[Union[str, int, List[str]]]=None) -> Opt[Union[str, int]]:
    if strg is None:
        return None
    elif isinstance(strg, str):
        ret = strg
        return ret
    elif isinstance(strg, list):
        ret = "".join(strg)
        return ret
    else:
        ret_int = strg
        return ret_int


x = funct(["str"])
print(x)
reveal_type(x)
