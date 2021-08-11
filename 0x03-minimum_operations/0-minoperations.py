#!/usr/bin/python3
'''Miunimum Operations'''
import sys


def minOperations(n):
    '''
    Method that calculates the fewest number of operations
    needed to result in exactly n
    '''

    chH = 2
    factList = []

    if (n <= 0):
        return (0)
    if (not isinstance(n, int)):
        return (0)
    if (n == 1):
        return (0)
    while (chH * chH <= n):
        if (n % chH):
            chH += 1
        else:
            '''
            Floor division - truncates the decimal
            and returns the integer result
            '''
            n //= chH
            factList.append(chH)
    if n > 1:
        factList.append(n)
    return (sum(factList))
