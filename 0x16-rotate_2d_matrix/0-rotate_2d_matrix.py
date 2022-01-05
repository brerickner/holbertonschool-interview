#!/usr/bin/python3
"""Rotate_2d_matrix"""


def rotate_2d_matrix(matrix):
    """Function rotate_2d_matrix -> takes 2d matrix as parameter."""
    """
        @matrix:
            2d matrix of integers
        Description:
            Rotates 2d matrix 90 degrees clockwise.
        Returns:
            Nothing. Rotate in place.
    """

    meow = [[]]
    meow = list(zip((*matrix[::-1])))
    for i in range(len(matrix)):
        for j in range(len(matrix[i])):
            matrix[i][j] = meow[i][j]
