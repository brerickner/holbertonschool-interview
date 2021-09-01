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
        for index, line in enumerate(fileinput.input()):
            status = int(line.split(" ")[-2])
            file_size += int(line.split(" ")[-1])
            if status in statusDict:
                statusDict[status] += 1

            if (index == 0 or index % 10 == 0):
                printStuff()

    # except KeyboardInterrupt:
    #     print("File size: {}".format(file_size))
    except Exception:
        print("File size: {}".format(file_size))
    finally:
        printStuff()
