#!/usr/bin/python3
"""
Given a list of non-negative integers representing the heights of walls with
unit width 1, as if viewing the cross-section of a relief map, calculate how
many square units of water will be retained after it rains.
"""
def rain(walls):
    """
    walls: list of non-negative integers.
    Return: Integer indicating total amount of rainwater retained.
    """
    wawaweewa = 0

    for x in range(1, len(walls) - 1):
        left = walls[x]
        for g in range(x):
            left = max(left, walls[g])
        right = walls[x]
        for g in range(x + 1, len(walls)):
            right = max(right, walls[g])
        wawaweewa += (min(left, right) - walls[x])

    return wawaweewa

