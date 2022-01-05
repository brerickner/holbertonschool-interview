#!/usr/bin/python3
'''Module that Rotate 2D Matrix 90 degrees clockwise'''


def rotate_2d_matrix(matrix):
    '''
    Rotates 2D matrix in-place 90 degrees to the right.
    Assume matrix has 2 dimensions and not empty.
    Return: void
    '''
    meow = [[]]
    meow = list(zip((*matrix[::-1])))
    for i in range(len(matrix)):
        for j in range(len(matrix[i])):
            matrix[i][j] = meow[i][j]
