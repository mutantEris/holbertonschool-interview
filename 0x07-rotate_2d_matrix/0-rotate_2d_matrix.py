#!/usr/bin/python3
"""make matrix go spin"""

def rotate_2d_matrix(matrix):
    """rotates matrix clockwise 90 degrees"""
    bigness= len(matrix[0])
    for x in range(bigness // 2):
        for g in range(x, bigness - x - 1):
            temp = matrix[x][g]
            matrix[x][g] = matrix[bigness - 1 - g][x]
            matrix[bigness - 1 - g][x] = matrix[bigness - 1 - x][bigness - 1 - g]
            matrix[bigness - 1 - x][bigness - 1 - g] = matrix[g][bigness - 1 - x]
            matrix[g][bigness - 1 - x] = temp