#!/usr/bin/python3



def makeChange(coins, total):
    """Make Chanhe"""
    if total < 0:
        return 0
    if total == 0:
        return 0

    dp = [float('inf')] * (total + 1)
    dp[0] = 0

    for c in coins:
        for i in range(c, total + 1):
            dp[i] = min(dp[i], dp[i - c] + 1)
    if dp[total] == float('inf'):
        return -1
    else:
        return dp[total]
