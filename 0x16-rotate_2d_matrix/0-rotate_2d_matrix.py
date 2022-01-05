#!/usr/bin/python3
""" Rotate_2d_matrix """


def rotate_2d_matrix(matrix):
    """ Function rotate_2d_matrix -> takes 2d matrix as parameter. """

    meow = [[]]
    meow = list(zip((*matrix[::-1])))
    for i in range(len(matrix)):
        for j in range(len(matrix[i])):
            matrix[i][j] = meow[i][j]
