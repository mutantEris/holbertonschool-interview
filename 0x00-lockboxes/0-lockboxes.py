#!/usr/bin/python3

def canUnlockAll(boxes):
    locker = [0]
    key = 0

    while key < len(locker):
        key = len(locker)
        for box in range(len(boxes)):
            if box in locker:
                for code in boxes[box]:
                    if code < len(boxes) and code not in locker:
                        locker.append(code)
    return len(locker) == len(boxes)