
def fib(n: int) -> tuple:
    a: int
    b: int
    i: int
    a, b = 1, 1
    for i in range(n):
        a, b = a + b, a
    return a


def rep_fib(repnum, fibnum):
    for i in range(repnum):
        a = fib(fibnum)
    return a
