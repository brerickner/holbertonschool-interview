#!/usr/bin/python3
'''Miunimum Operations'''

def minOperations(n):
    '''Method that calculates the fewest number of operations
    needed to result in exactly n'''
    if (n <= 0):
        return 0
    if (type(n) == "int"):
        print ("meow")
        return 0
    if (n == 1):
        return 0
    
    # copy starts at 2
    copies = 2
    ops = 0
    
    while (ops <= n):
        if (n % copies == 0):
            copies += 1
        else:
            n /= copies
            ops += copies
    return (ops)




            
