#!/usr/bin/python3
'''Miunimum Operations'''
import sys


def minOperations(n):
    '''
    Method that calculates the fewest number of operations
    needed to result in exactly n
    '''

    ops = 2
    factList = []

    if (n <= 0):
        return (0)
    if (not isinstance(n, int)):
        return (0)
    if (n == 1):
        return (0)
    while (ops * ops <= n):
        if (n % ops):
            ops += 1
        else:
            '''
            Floor division - truncates the decimal
            and returns the integer result
            '''
            n //= ops
            factList.append(ops)
    if n > 1:
        factList.append(n)
    return (sum(factList))
