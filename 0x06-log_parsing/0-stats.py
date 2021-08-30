#!/usr/bin/python3
"""Command line metric getter"""

import os
import sys
import fileinput

thisList = []
statusDict = {200: 0, 301: 0, 400: 0, 401: 0, 403: 0, 404: 0, 405: 0, 500: 0}
file_size = 0

try:
    for index, line in enumerate(fileinput.input()):
        file_size += int(line.split(" ")[-1])
except KeyboardInterrupt: 
    print("File size: {}".format(file_size))
