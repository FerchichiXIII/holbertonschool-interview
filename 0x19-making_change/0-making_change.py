#!/usr/bin/python3

"""
    Given a pile of coins of different values,
    determine the fewest number of coins needed to meet a given amount total.
"""


def makeChange(coins, total):
    """Make Chanhe"""
    if total <= 0:
        return 0

    dp = [float('inf')] * (total + 1)
    dp[0] = 0

    for c in coins:
        for i in range(c, total + 1):
            dp[i] = min(dp[i], dp[i - c] + 1)
    return dp[total] if dp[total] != float('inf') else -1
