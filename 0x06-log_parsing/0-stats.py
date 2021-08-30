#!/usr/bin/python3
"""Command line metric getter"""

import os
import sys
import fileinput

try:
    for line in fileinput.input():
        print("Meow {}", format(line))
except KeyboardInterrupt:
    sys.exit()
