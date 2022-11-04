#!/usr/bin/python3
"""make matrix go spin"""


def rotate_2d_matrix(matrix):
    """rotates matrix clockwise 90 degrees"""
    size= len(matrix[0])
    for x in range(size // 2):
        for g in range(x, size - x - 1):
            temp = matrix[x][g]
            matrix[x][g] = matrix[size - 1 - g][x]
            matrix[size - 1 - g][x] = matrix[size - 1 - x][size - 1 - g]
            matrix[size - 1 - x][size - 1 - g] = matrix[g][size - 1 - x]
            matrix[g][size - 1 - x] = temp
            