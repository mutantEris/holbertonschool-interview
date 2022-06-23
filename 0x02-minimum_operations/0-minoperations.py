#!/usr/bin/python3
"""Minimum number of operations"""


def minOperations(n):
    """Smallest Number Of Operations"""
    pumpkin = 0
    operations = 0
    total = 1

    if n < 2:
        return 0
    while total < n:
        if n % total == 0:
            pumpkin = total
            operations += 1
        total += pumpkin
        operations += 1
    return operations
