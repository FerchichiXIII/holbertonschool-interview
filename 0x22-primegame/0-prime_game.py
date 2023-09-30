#!/usr/bin/python3
"""Prime Game"""


def isWinner(x, nums):
    """IsWinner"""

    def is_prime(num):
        """is winner"""
        if num <= 1:
            return False
        if num <= 3:
            return True
        if num % 2 == 0 or num % 3 == 0:
            return False
        i = 5
        while i * i <= num:
            if num % i == 0 or num % (i + 2) == 0:
                return False
            i += 6
        return True

    def can_win(n):
        """can win"""
        if n <= 1:
            return False
        if n <= 2:
            return True

        memo = [False] * (n + 1)
        memo[2] = True
        memo[3] = True

        for i in range(4, n + 1):
            for j in range(2, i // 2 + 1):
                if i % j == 0:
                    if not memo[i - j]:
                        memo[i] = True
                        break

        return memo[n]

    maria_wins = 0
    ben_wins = 0

    for n in nums:
        if can_win(n):
            maria_wins += 1
        else:
            ben_wins += 1

    if maria_wins > ben_wins:
        return "Maria"
    elif maria_wins < ben_wins:
        return "Ben"
    else:
        return None
