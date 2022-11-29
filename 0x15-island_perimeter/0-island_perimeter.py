#!/usr/bin/python3
"""island perimeter"""


def island_perimeter(grid):
    """Returns perimeter of the island"""
    perimeter = 0
    for g in range(len(grid)):
        for x in range(len(grid[g])):
            if grid[g][x] == 1:
                perimeter += 4
                if g > 0 and grid[g - 1][x] == 1:
                    perimeter -= 2
                if x > 0 and grid[g][x - 1] == 1:
                    perimeter -= 2
    return perimeter
    