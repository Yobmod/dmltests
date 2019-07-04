#!python
#cython: language_level=3
"""run with command -> python setup.py build_ext --inplace"""
try:
    from setuptools import setup
    from setuptools import Extension
except ImportError:
    from distutils.core import setup
    from distutils.extension import Extension

from Cython.Build import cythonize
# from Cython.Distutils import build_ext
# import numpy as np # if it requires numpy


extensions = [Extension("*", ["*.pyx"])]


setup(
    name='Generic model class',
    # cmdclass = {'build_ext': build_ext},
    # include_dirs = [np.get_include()], # only if it requires numpy
    ext_modules=cythonize(extensions,
                          build_dir="build",  # puts .c and .html here
                          annotate=True,  # generate .html
                          language_level='3',  # python version
                          # language='c',  # 'c' or 'c++'
                          compiler_directives={'embedsignature': True,
                                               'warn.undeclared': True,
                                               'warn.unused_arg': True,
                                               'warn.unused': True,
                                               'warn.unused_result': True,

                                               }
                          )
)
