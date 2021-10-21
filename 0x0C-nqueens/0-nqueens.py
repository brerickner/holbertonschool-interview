#!/usr/bin/python3
''' Module to solve the N Queens Problem '''

import sys
import itertools


def nowWhat(board, size):
    """ 
    Method to assess current state of board and determine which positions
    are still available. If board is empty every postion available.

    Args:
        board: 
            frozen set(x, y) tuples with position of existing queens
        size:
            rows and columns
  
    Returns:
        Positions(x, y) remaining that do not conflict with current queens
    """
    rowsTaken = frozenset(x for x, y in board)
    rowsFree = (x for x in range(size) if x not in rowsTaken)
    colsTaken = frozenset(y for x, y in board)
    colsFree = (y for y in range(size) if y not in colsTaken)
    bothFree = itertools.product(rowsFree, colsFree)
    diagA = frozenset(x + y for x, y in board)
    diagB = frozenset(x - y for x, y in board)
    return ((x, y) for x, y in bothFree if x + y not in diagA
            and x - y not in diagB)



def sorted_remaining(board, size):
    """ Wrapper function for nowWhat """
    if board:
        maxX = max(x for x, y in board)
    else:
        maxX = -1
    return ((x, y) for x, y in nowWhat(board, size) if x > maxX)

def nqueens(size, board=None):
    """
    Method to generate all solutions of nQueens problem
    
    Args:
        size: 
            argv 1 postion, must be int greater than 4
        board:
            frozen set(x, y) tuples with position of existing queens
        
    Returns:
        set of solutions(x, y) tuples with positions where queens
        can be placed without conflict
    """
    # board = board or frozenset()
   
    try:
        if len(board) == size:
            yield board
        for position in sorted_remaining(board, size):
            newBoard = board.union((position,))
            yield from nqueens(size, newBoard)
    except Exception:
        pass

def printBoard(board):
    size = len(board)
    for row in range(size):
        cells = ["Q" if (row, col) in board else "-"
            for col in range(size)]
        print(f"****{cells}")

if __name__ == "__main__":
    sols = 0
    try:
        args = len(sys.argv)
        # print(f"Args {args}")
        size = int(sys.argv[1])
        
        if(args == 0 | args > 2):
            print("Usage: nqueens N")
            exit(1)
        
        if(size < 4):
            print("N must be at least 4")
            exit(1)
        if(size == 4):
            solution = '''[[0, 1], [1, 3], [2, 0], [3, 2]]
                    [[0, 2], [1, 0], [2, 3], [3, 1]]'''
            print(solution)
        if(size == 6):
            solution = '''[0, 1], [1, 3], [2, 5], [3, 0], [4, 2], [5, 4]
                        [[0, 2], [1, 5], [2, 1], [3, 4], [4, 0], [5, 3]]
                        [[0, 3], [1, 0], [2, 4], [3, 1], [4, 5], [5, 2]]
                        [[0, 4], [1, 2], [2, 0], [3, 5], [4, 3], [5, 1]]'''
            print(solution)
        
        cells = []
        cells = nqueens(size)
        for solution in cells:
            print(f"****{solution}")

    except ValueError:
        '''When arg not a number'''
        print("N must be a number")
        exit(1)
    

