import ctypes
import os
import site

GIT_DIR = os.path.dirname(os.path.dirname(os.path.dirname(os.path.dirname(os.path.abspath(__file__)))))
print(GIT_DIR)

GEO_DIR = os.path.join(GIT_DIR, 'OSGEO4W64')
print(GEO_DIR)

BIN_DIR = os.path.join(GEO_DIR, 'bin')
print(BIN_DIR)

DLL_PATH = os.path.join(BIN_DIR, 'gdal111.dll')
print(DLL_PATH)

try:
    path = os.environ['PATH']
    print(path)
    ctypes.CDLL(DLL_PATH)
except Exception as e:
    print(e, 'blaj')
else:
    print('done')