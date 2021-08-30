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
        status = int(line.split(" ")[-2])
        if (index == 0 or index % 10 == 0):
            file_size += int(line.split(" ")[-1])
            print("File size: {}".format(file_size))
        if status in statusDict:
            statusDict[status] += 1
            print("{}: {}".format(status, statusDict[status]))
            
except KeyboardInterrupt: 
    print("File size: {}".format(file_size))
except Exception:
    pass
finally:
    print("File size: {}".format(file_size))
    if (status in statusDict):
        statusDict[status] += 1
        print("{}: {}".format(status, statusDict[status]))
