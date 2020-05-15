from distutils.core import setup
from distutils.extension import Extension
from Cython.Build import cythonize

examples_extension = Extension(
    name="wrap",
    sources=["wrap.pyx", "hello.c"],
    #libraries=["hello"],
    #library_dirs=["."],
    #include_dirs=["."]
)

setup(
    name="wrap",
    ext_modules=cythonize([examples_extension],
                          annotate=True,
                          compiler_directives={'language_level' : "3"},
    )
)