from __future__ import annotations
from mypy.erasetype import erase_type
from mypy.erasetype import TypeVarEraser
from typing import TypeVar
from typing import NewType
from typing import Type
from typing import Any
from typing import Dict
from dataclasses import dataclass, asdict
from func_timeout.exceptions import FunctionTimedOut
import ctypes
from typing import cast
from time import sleep
from ctypes import c_byte, c_short, c_int
from termcolor import colored
from rapidtables import format_table, FORMAT_GENERATOR_COLS
from ordered_set import OrderedSet
from collections import Counter, namedtuple, deque
from array import array
from func_timeout import func_set_timeout, func_timeout
from mypy_extensions import TypedDict
from typing import List, Optional, NamedTuple, Callable
import cytoolz as toolz
from cytoolz import curry

# ----------------------------------------------------------------------


def compose_two(func1: Callable, func2: Callable) -> Callable:
    def curried(*args: Any, **kwargs: Any) -> Any:
        return func2(func1(*args, **kwargs))
    return curried


def calc_BMI(weight: float, height: float) -> float:
    return weight / height**2


def evaluate_BMI(bmi: float) -> str:
    if bmi < 18.5:
        text = colored("Underweight", 'red')
    elif bmi < 25:
        text = "Normal (healthy weight)"
    elif bmi < 30:
        text = colored("Overweight", 'red')
    else:
        text = colored("Obese", 'red', attrs=['underline'])
    return f"BMI = {bmi:.1f}, {text}"


BMI_judge = compose_two(calc_BMI, evaluate_BMI)

weight = 1.0  # sentinal
while weight > 0:
    weight = float(input("weight (kg) "))
    height = float(input("height (m) "))
    print(BMI_judge(weight, height))


@curry
def BMI_judge_toolz(weight: float, height: float) -> str:
    return "seems pointless"


# ---------------------------------------------------------------------
def receives_OrderedSet_int(ordered_set: OrderedSet[int]) -> None:
    print(ordered_set)


letters = OrderedSet('abracadabra')
numbers = OrderedSet([1, 2, 3, 4, 5, 5, 5])
set_num = set([1, 2, 3, 4, 5, 5, 5])
os_num = OrderedSet(set_num)


# receives_OrderedSet_int(letters)  # should error
receives_OrderedSet_int(numbers)  # no error

# receives_OrderedSet_int(set_num)  # should error
receives_OrderedSet_int(os_num)  # no error


# ---------------------------------------------------------------------------------------------
# if you need to keep strict column ordering, use OrderedDict for the rows
JobsDict = TypedDict('JobsDict', {'name': str, 'salary': Optional[int], 'job': str}, total=True)


class JD(TypedDict, total=True):
    name: str
    salary: Optional[int]
    job: str


person: JD = {'name': 'John', 'salary': 2000, 'job': 'DevOps'}

data: List[JobsDict] = [
    {'name': 'John', 'salary': 2000, 'job': 'DevOps'},
    {'name': 'Jack', 'salary': 2500, 'job': 'Architect'},
    {'name': 'Diana', 'salary': None, 'job': 'Student'},
    {'name': 'Ken', 'salary': 1800, 'job': 'Q/A'},
    # {'name': 'Kelly', 'salary': 120},  # error, missing job
    # {'name': 'Karen', 'salary': '12', 'job': 'Q/A'}  # error, salary should be int
]

header, rows = format_table(data, fmt=FORMAT_GENERATOR_COLS)
spacer = '  '
print(colored(spacer.join(header), color='blue'))
print(colored('-' * sum([(len(x) + 2) for x in header]), color='grey'))
for r in rows:
    print(colored(r[0], color='white', attrs=['bold']) + spacer, end='')
    print(colored(r[1], color='cyan') + spacer, end='')
    print(colored(r[2], color='yellow'))


# ------------------------------------------------------------------------------------------------

my_list_ints: List[int] = [1, 3, 4, -5, 12]
try:
    my_array_chars: array[c_byte] = array('b', my_list_ints)  # type: ignore  # 'b' 1 byte -128 <= int < 128 e.g. ctype.signedchar
    my_array_short_ints: array[c_short] = array('h', my_list_ints)  # type: ignore # 'h' 2 byte int <= 65535 e.g. ctype.short
    my_array_ints: array[c_int] = array('i', my_list_ints)    # type: ignore # ''l'' 4 bytes e.g. ctype.unsignedint
except OverflowError as err:
    print(err)
else:
    print(my_array_chars)


def takes_short_int(inp: c_short) -> None:
    """c_byte: 1
    c_short: 2
    c_int: 4
    """
    assert ctypes.sizeof(inp) == 2


takes_short_int(c_short(4000))
# -------------------------------------------------------------------------------------------------

my_deque_ints = deque(my_list_ints)
my_set_ints = set(my_list_ints)
my_ordset_ints = OrderedSet(my_list_ints)

# ----------------------------------------------------------------------------------


class MyNamedTup(NamedTuple):
    name: str
    job: str
    salary: int
    year: int


my_tuple = ('this', 'that', 10000, 5)
my_namedtuple = MyNamedTup('this', 'that', 5000, 1)

name1 = my_tuple[0]
name2 = my_namedtuple.name
assert my_namedtuple[0] == my_namedtuple.name


# -------------------------------------------------------------
@func_set_timeout(1, allowOverride=True)
def long_function(inp: int) -> bool:
    """optional "forceTimeout" kwarg added to function to override default timeout"""
    x = inp * 1000
    sleep(2)
    if x > 1000:
        return True
    else:
        return False


try:
    worked = long_function(2)
except FunctionTimedOut as e:
    func_name = colored(str(e.timedOutFunction).split()[1], color='red')
    func_args = colored(e.timedOutArgs, color='red')
    print(f"{func_name}{func_args} timed out {e.timedOutAfter} seconds. Retrying...")
    worked = e.retry(timeout=5)
finally:
    print(worked)

# -----------------------------------------------------------------------------------------------------
@dataclass
class InventoryItem:
    '''Class for keeping track of an item in inventory.'''
    name: str
    unit_price: float
    quantity_on_hand: int = 0

    def total_cost(self) -> float:
        return self.unit_price * self.quantity_on_hand


item1 = InventoryItem('Jim', 3.55, 2)
print(item1.total_cost())
