# moshmosh?
# +pipeline
# +quick-lambda
# +pattern-matching
# +scoped-operator(-, list_diff)
# +lazy-import
import numpy as np
# -lazy-import


# quick-labdas?, use _ ??????????????????????????????????????????????????????????????

from functools import reduce
if reduce(_0 + _1, [1, 2, 3]) == 6:
    print("worked")

# pipeline, pipe functions -----------------------------------------------------------

input1 = 123
input2 = 456

input1 + input2 | str | print


# pattern match --------------------------------------------------------------------

data_to_match = 123

with match(data_to_match):
    if 1 or 2 or 3:
        res = "single figure"
    if 123:
        res = 123

print(res)


# scoped operators, define operator as function -------------------------------------

def list_diff(a, b):
    return [e for e in a if e not in b]


opr_list = [1, 2, 3] - [1, 2]
print(opr_list)

# +scoped-operator(**, my_lol_func)


def my_lol_func(loler, lolee):
    return f"{loler} lols at {lolee}"


print("i" ** "you")


# lazy import, module oly imported when used -------------------------------------

my_array = np.array([1, 2, 3])

print(my_array)
