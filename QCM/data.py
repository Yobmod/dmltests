# -*- coding: utf-8 -*-
"""
Created on Tue Feb  6 14:13:15 2018

@author: laventin
"""

import os


os.chdir(r'.')

f = open("STRo0016.GRF", "rb")
outputlist = []

try:
    line = f.readline(55)
# print(line)
    text = line.decode("ISO 8859-1 ")
    print(text)
except:
    pass

f.close()
print("done")
    #print(outputlist)
