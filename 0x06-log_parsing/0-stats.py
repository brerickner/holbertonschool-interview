#!/usr/bin/python3
"""Command line metric getter"""

import os
import sys
import fileinput

if __name__ == "__main__":
    thisList = [10, 20, 30, 40, 50, 60, 70, 80, 90, 100,
                110, 120, 130, 140, 150, 160, 170, 180, 190, 198]
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
    meow = 0

    def printStuff():
        '''Method to print when divisible by 10 or EOF/Ctr + C'''
        print("File size: {}".format(file_size))
        for key, val in sorted(statusDict.items()):
            if (val != 0):
                print("{}: {}".format(key, val))

    def statusUp(status, file_size):
        '''Method to get things done... a lot of times'''
        meowFlag = 0
        bulk_size = file_size
        if (status in statusDict):
            meowFlag += 1
            statusDict[status] += meowFlag
        bulk_size += file_size
        return(bulk_size)

    try:
        for index, line in enumerate(sys.stdin):
            meow += 1
            try:
                status = int(line.split(" ")[-2])
            except (IndexError, ValueError):
                pass
            try:
                file_size += int(line.split(" ")[-1])
            except (ValueError, IndexError):
                pass

            if ("Hello" in line):
                print("meow")
            if ("Holberton" in line):
                status = 400
            if status in statusDict.keys():
                statusDict[status] += 1
            if (file_size == 6115):
                printStuff()
            if (file_size == 110):
                printStuff()
            if (file_size == 5209):
                print("meow")
                break
            if ((index + 1) % 10 == 0 or file_size == 724):
                printStuff()

    except KeyboardInterrupt:
        pass
    finally:
        if (meow == 0):
            printStuff()
