# -*- coding: utf-8 -*-
"""
Created on Thu Feb  8 10:40:16 2018

@author: laventin
"""

import numpy as np                        # type: ignore
import matplotlib.pyplot as plt            # type: ignore
from scipy.stats import linregress        # type: ignore
from typing import List, Tuple, Union, NoReturn, Optional, Any


# types

TupFlType = Tuple[float, ...]
OptTupFlType = Optional[TupFlType]
NumType = Union[int, float]
IterNumType = Union[List[NumType], Tuple[NumType, ...]]


# data

meas_y = (  -4.2,     -4.1,   -3.8,   -3.62,  -3.6,   -3.6)               # X
meas_x = (  -2.7,     -2.52,  -2.4,   -2.3,   -2.22,  -2.15)           # Y
err_y = (   0.21,     0.18,   0.17,   0.05,     0.05, 0.04)


# calulations

def plot_LSfit(meas_x: TupFlType, meas_y: TupFlType) -> NoReturn:
    linfit = np.polyfit(meas_x, meas_y, 1)     # linear regression, var = [gradient, intercept]
    linfit_func = np.poly1d(linfit)                    # trendline
    plt.plot(meas_x, linfit_func(meas_x), 'g')
    
    m, c = np.polyfit(meas_x, meas_y, 1, w = [1.0 / ty for ty in err_y])
    WLS_y = (np.multiply(meas_x, m)) + c
    print(WLS_y)
    plt.plot(meas_x, WLS_y, 'r')
    plt.scatter(meas_x, meas_y, s=20, c='g')
    
    plt.axis([-2.8, -1.8, -4.6, -3])        # [xmin, xmax, ymin, ymax]
    plt.show()

    lininfo = linregress(meas_x, meas_y)
    print(lininfo) 
    line_eqn = "y=%.6fx+(%.6f)" % (linfit[0], linfit[1])
    print("linear fit line : " + line_eqn)
    
def plot_WLSfit(meas_x: TupFlType, meas_y: TupFlType, err_y: OptTupFlType=None, ) -> NoReturn:
    
    m, c = np.polyfit(meas_x, meas_y, 1, w = 1.0 / np.array(err_y))
    trend_weighted = "y=%.6fx+(%.6f)" % (m, c)
    print("WLS fit line weight : " + trend_weighted)



plot_LSfit(meas_x, meas_y)
plot_WLSfit(meas_x, meas_y, err_y)