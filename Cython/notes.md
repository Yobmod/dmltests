
# Cython notes

Write functions as .py or .pyx
    cython xxx.py(x) --> xxx.c

Create compile.py that cythonizes .py(x)
    python compile.py build_ext --inplace   --> xxx.c, xxx.platform.so/.pyd


Import xxx.pyd to use
    import xxx

if .sp/.pyd present, prefers them



# compiler versions windows

https://matthew-brett.github.io/pydagogue/python_msvc.html
Cpython 3.6.0	 msvc 14.0+   VS2015+   32 & 64 bit
Cpython 3.7.0	 msvc 14.1   VS2017   32 & 64 bit
Cpython 3.8.0	 msvc 14.1   VS2017   32 & 64 bit
\\Cpython 3.9.0	 msvc 14.2   VS2019   32 & 64 bit
