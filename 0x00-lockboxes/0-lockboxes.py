#!/usr/bin/python3

"""determines if all the boxes can be opened"""


def canUnlockAll(boxes):
    """can unlock alll"""

    newlist = [0]
    k = len(boxes)
    for i in boxes:
        if len(i) == 0 and i is not boxes[k-1]:
            return False

    for index, k in enumerate(boxes):
        if index in newlist or index < k-1:
            return True
        else:
            return False
