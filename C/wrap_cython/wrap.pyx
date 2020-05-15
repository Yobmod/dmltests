cdef extern from "hello.h":
    int hello()
    int add(int, int)

def py_hello() -> None:
    hello()

def py_add() -> int:
    num1str = input("Enter first number:")
    try: 
        num1 = int(num1str)
    except Exception:
        pass

    num2str = input("Enter second number:")
    try: 
        num2 = int(num2str)
    except Exception:
        pass

    res = add(num1, num2)
    return res