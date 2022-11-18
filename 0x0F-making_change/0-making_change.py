#!/usr/bin/python3
'''Sorts and counts coins'''


def makeChange(coins, total):
    '''Counts the coins I found in my couch'''
    count = 0
    coins.sort(reverse=True)
    for coin in coins:
        count += total // coin
        total %= coin
    return -1 if total else count
    