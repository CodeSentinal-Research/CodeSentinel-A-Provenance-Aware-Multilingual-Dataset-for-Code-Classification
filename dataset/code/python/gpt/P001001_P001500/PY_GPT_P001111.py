# problem title : Snake and Ladder Minimum Dice Throws
# Solve the stated task using standard input and standard output.
from typing import List
from collections import deque

def snakes_and_ladders(board: List[int]) -> int:
    n = 30
    vis = [False] * (n + 1)
    q = deque([(1, 0)])
    vis[1] = True

    while q:
        curr, steps = q.popleft()
        if curr == n:
            return steps
        for dice in range(1, 7):
            next_pos = curr + dice
            if next_pos <= n:
                if board[next_pos] != -1:
                    next_pos = board[next_pos]
                if not vis[next_pos]:
                    vis[next_pos] = True
                    q.append((next_pos, steps + 1))
    return -1

if __name__ == '__main__':
    n_moves = int(input())
    board = [-1] * 31
    for _ in range(n_moves):
        u, v = map(int, input().split())
        board[u] = v
    print(snakes_and_ladders(board))
