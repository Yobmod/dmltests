# cython: profile=True

cdef inline (long long, long long) fib(int n) nogil:
    cdef int i
    cdef long long a, b
    a, b  = 1, 1
    for i in range(n):
       a, b = a+b, a
    return a

cpdef long long rep_fib(int repnum, int fibnum):
    cdef int i
    cdef long long a, _
    for i in range(repnum):
        a = fib(fibnum)
    return a