#!/usr/bin/python3
""" Module to calculate the perimeter of an island """

def island_perimeter(grid):
    """
    Method to calculate the perimeter of an island made of 1's. Each side is length 1.
    Args:
        grid: list of  list of 0's representing 'water' and 1's representing 'land'.
        It is rectangular with its width and height not exceeding 100.
    Returns:
        The total perimeter of the island as an int
    """
    peri = 0
    for index, row in enumerate(grid):
        print(f"row {index}: {row}")
        for col in row:
            if col == 1:
                print(f"[{index}][{col}] + 2")
                peri += 2
     
    return (peri)

            # if 1 and along the top/botom/left/right edge + 1 to perimeter
            # if col == 1 and row == 0 or row == len(row - 1):
            #     print(f"col:{col}")