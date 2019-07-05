import cProfile
from dml import fib_py, fib_my, fib_cy
import test
import sys
sys.path.append("/dml/")

pr = cProfile.Profile(timeunit=1000)
pr.enable()

x = 50
reps = 10000000

py_result = fib_py.rep_fib(reps, x)
cy_result = fib_cy.rep_fib(reps, x)
my_result = fib_my.rep_fib(reps, x)
nuit_result = test.rep_fib(reps, x)


print(py_result)
print(cy_result)
print(my_result)
print(nuit_result)

print(py_result == my_result)

pr.disable()
pr.print_stats(sort='ncalls')  # 'time, 'cumtime'

# python -m cProfile -s cumtime main.py
# python -m cProfile -s time main.py
