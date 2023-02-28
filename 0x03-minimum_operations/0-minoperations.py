#!/usr/bin/python3


"""
calculates the fewest number of operations .
"""
import math


def minOperations(n):

    if n == 1:
        return 0
    for i in range(2, int(math.sqrt(n))+1):
        if n % i == 0:
            return i + minOperations(n // i)
    return n
