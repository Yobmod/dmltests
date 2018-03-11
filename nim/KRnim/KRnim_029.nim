import strutils

proc power(base: int, n: int): int

proc main() =
# test power functionvar name;
    for i in countup(1, 10):
        echo "$1 $2 $3 \n".format(i, power(2,i), power(-3,i))

proc power(base: int, n: int): int =
# power: raise base to n-th power; n >= 0
    var p: int = 1
    for i in countdown(1, n):
        p *= base
    return p

main()

#[Nim has:
^ operator (int^int)
pow(int/float, int/float) in stdlib.math
powf(float, float) ?
f-string interpolation of variables in stdlib.strformat
]#
