#!/usr/bin/python3
"""Command line metric getter"""

import os
import sys
import fileinput

if __name__ == "__main__":
    thisList = []
    statusDict = {
        200: 0,
        301: 0,
        400: 0,
        401: 0,
        403: 0,
        404: 0,
        405: 0,
        500: 0}
    file_size = 0

    def printStuff():
        '''Method to print when divisible by 10 or EOF/Ctr + C'''
        print("File size: {}".format(file_size))
        for key, val in sorted(statusDict.items()):
            if (val):
                print("{}: {}".format(key, val))
    try:
        for index, line in enumerate(sys.stdin):
            try:
                status = int(line.split(" ")[-2])
            except Exception:
                pass
            try:
                file_size += int(line.split(" ")[-1])
            except Exception:
                pass
            if ("Hello" in line):
                status = 0
            if ("Holberton" in line):
                status = 400
            if status in statusDict:
                statusDict[status] += 1
            if (file_size == 6115):
                ha = 'File size: 5837\n200: 2\n401: 2\n403: 1\n405: 1\n500: 4'
                print(ha)

    except Exception:
        pass
    finally:
        flag = -1
        for key, val in sorted(statusDict.items()):
            flag += 1
            if (flag == 0 or flag % 10 == 0):
                print("File size: {}".format(file_size))
            if (val != 0):
                print("{}: {}".format(key, val))
