#!/usr/bin/python3
"""N queens classical problem."""
import sys

def get_solutions(board, n):
    """Get solutions from board."""
    solutions = []
    for x in range(n):
        for y in range(n):
            if board[x][y]:
                solutions.append([x, y])
    return solutions

def is_valid_position(board, position, n):
    """Check if position is valid on the board."""
    for i in range(0, n):
        if board[position[0]][i]:
            return False
        if board[i][position[1]]:
            return False
        if position[0] + i < n and position[1] + i < n:
            if board[position[0] + i][position[1] + i]:
                return False
        if position[0] - i >= 0 and position[1] - i >= 0:
            if board[position[0] - i][position[1] - i]:
                return False
        if position[0] + i < n and position[1] - i >= 0:
            if board[position[0] + i][position[1] - i]:
                return False
        if position[0] - i >= 0 and position[1] + i < n:
            if board[position[0] - i][position[1] + i]:
                return False
    return True

def solve_n_queen(board, col, n):
    """Solve N queens using backtracking."""
    if col >= n:
        print(get_solutions(board, n))
        return
    for i in range(n):
        if is_valid_position(board, (i, col), n):
            board[i][col] = True
            solve_n_queen(board, col + 1, n)
            board[i][col] = False

def main():
    """Solve N queens using backtracking."""
    if len(sys.argv) == 1:
        print("Usage: nqueens N")
        exit(1)
    try:
        N = int(sys.argv[1])
    except ValueError:
        print("N must be a number")
        exit(1)

    if N < 4:
        print('N must be at least 4')
        exit(1)
    board = [[False for _ in range(N)] for _ in range(N)]

    solve_n_queen(board, 0, N)

if __name__ == "__main__":
    main()
