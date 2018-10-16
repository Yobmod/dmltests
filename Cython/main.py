import sys; sys.path.append("/dml/")
from dml import fib_py, fib_my, fib_cy
import cProfile

pr = cProfile.Profile(time_unit=1000) 
pr.enable()

x = 50
reps = 1000000

py_result = fib_py.rep_fib(reps, x)
cy_result = fib_cy.rep_fib(reps, x)
my_result = fib_my.rep_fib(reps, x)

print(py_result)
print(cy_result)
print(my_result)

print(py_result==cy_result)

pr.disable()
pr.print_stats(sort='cumtime')

# python -m cProfile -s cumtime main.py
# python -m cProfile -s time main.py