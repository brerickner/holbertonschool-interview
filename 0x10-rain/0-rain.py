#!/usr/bin/python3
'''Module Rain'''


def rain(walls):
    '''
    Function Rain -> takes positive int 'walls' as parameter
    @walls:
        list of "+" integers representing height of each wall with width of 1.
    Description:
        Calculate how many sq. units of water will be retained when it rains.
        Water is stored when wall to the right or left has a greater height.
    Returns:
        Integer value representing amount of water retained.
        If list is empty, return 0.
    '''
    size = len(walls)

    if size == 0:
        return 0

    ''' left[i] and right[i] contain height of tallest wall'''
    left = [0] * size
    right = [0] * size
    amtWater = 0

    '''Left'''
    left[0] = walls[0]
    for i in range(1, size):
        left[i] = max(left[i - 1], walls[i])

    '''Right'''
    right[-1] = walls[-1]
    for i in range(size - 2, -1, -1):
        right[i] = max(right[i + 1], walls[i])

    '''Wall i water accumulated with be equal to the min left/right
    wall minus current wall height of array'''
    for i in range(0, size):
        amtWater += min(left[i], right[i]) - walls[i]
    return (amtWater)
