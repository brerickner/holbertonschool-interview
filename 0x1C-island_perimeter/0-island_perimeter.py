#!/usr/bin/python3
""" Module to calculate the perimeter of an island """


def island_perimeter(grid):
    """
    Method to calculate the perimeter of an island made of 1's.
    Each side is length 1.
    Args:
        grid: list of  list of 0's representing 'water' and 1's
        representing 'land'.
        It is rectangular with its width and height not exceeding 100.
    Returns:
        The total perimeter of the island as an int
    """
    peri = 0
    for index, row in enumerate(grid):
        for cIndex, col in enumerate(row):
            if col == 1 and index >= 0 and cIndex >= 0:
                if index == 0:
                    up = 0
                else:
                    up = grid[index - 1][cIndex]
                if cIndex == 0:
                    left = 0
                else:
                    left = grid[index][cIndex - 1]
                try:
                    down = grid[index + 1][cIndex]
                except IndexError:
                    down = 0
                try:
                    right = grid[index][cIndex + 1]
                except IndexError:
                    right = 0

                # print(f"**[{index}, {cIndex}]**")
                # print(f"up: {grid[index-1][cIndex]}")
                # print(f"right: {grid[index][cIndex + 1]}")
                # print(f"down: {grid[index + 1][cIndex]}")
                # print(f"left: {grid[index][cIndex - 1]}")
                # print("\n")
                if up == 0:
                    # print("up +1")
                    peri += 1
                if right == 0:
                    # print("rt +1")
                    peri += 1
                if down == 0:
                    # print("dwn +1")
                    peri += 1
                if left == 0:
                    # print("lft +1")
                    peri += 1
                # if ((index - 1) == 0) or ((index + 1) == 0):

    return (peri)

    # if 1 and along the top/botom/left/right edge + 1 to perimeter
    # if col == 1 and row == 0 or row == len(row - 1):
    #     print(f"col:{col}")
