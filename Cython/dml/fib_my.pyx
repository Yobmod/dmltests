# cython: profile=True
import cython

# from libc.stdint cimport int64_t
@cython.nogil  # uses threads
@cython.inline  # substitutes the code whereever the function is called
@cython.ccall  # cdef
def fib(n: cython.int) -> cython.longlong:
    a: cython.longlong
    b: cython.longlong
    i: cython.int
    a, b  = 1, 1
    for i in range(n):
       a, b = a+b, a
    return a


@cython.ccall  # cpdef
def rep_fib(repnum: cython.int, fibnum: cython.int) -> cython.longlong:
    i: cython.int
    a: cython.longlong
    _: cython.longlong
    for i in range(repnum):
        a, _ = fib(fibnum)
    return a


"""
cython types -> int (32), long (32?), longlong (64), bint (bool), str, double (64), float (32), longdouble (80?)  struct
cython.int ==  int64_t on win64  # from libc.stdint cimport uint32_t, int64_t, etc
The class decorator @cython.cclass creates a cdef class.
The function/method decorator @cython.cfunc creates a cdef function.
@cython.ccall creates a cpdef function, i.e. one that Cython code can call at the C level.
@cython.locals declares local variables (see above). It can also be used to declare types for arguments, i.e. the local variables that are used in the signature.
@cython.inline is the equivalent of the C inline modifier.
@cython.final terminates the inheritance chain by preventing a type from being used as a base class, 
or a method from being overridden in subtypes. This enables certain optimisations such as inlined 
method calls."""