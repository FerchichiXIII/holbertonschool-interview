#!/usr/bin/python3

"""determines if all the boxes can be opened"""


def canUnlockAll(boxes):
    """can unlock alll"""

    k = [0]
    for key in k:
        for index in boxes[key]:
            if index not in k and index < len(boxes):
                k.append(index)
    for i in range(len(boxes)):
        if i not in k:
            return False
    return True
