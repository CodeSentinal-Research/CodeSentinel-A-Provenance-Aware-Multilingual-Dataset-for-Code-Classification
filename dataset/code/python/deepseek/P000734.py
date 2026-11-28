Sure, here is a Python solution for the Knight's Tour problem. The code uses the A* Search algorithm to find the shortest path from the given start position to all other positions on the chessboard.

import sys
import heapq

def heuristic(a, b):
    return abs(a // N - b // N) + abs(a % N - b % N)

def astar(start):
    pq = [(0, start, [])]
    seen = set()
    while len(pq) > 0:
        (cost, node, path) = heapq.heappop(pq)
        if node not in seen:
            seen.add(node)
            if len(path) == N*N:
                return path + [node]
            for (c, n) in [(1, node[0]+a[0]), (1, node[1]+a[1])]:
                if 0 <= c < N and (c, n) not in [(x, y) for (x, y) in seen]:
                    heapq.heappush(pq, (cost+1, [c, n] + path, [node, (c, n)]))
    return -1

def solve(N, row, col):
    global a, board
    a = [0] * N * N
    board = [[0] * N for _ in range(N)]
    board[row][col] = 1
    path = astar([row, col])
    if path == -1:
        print("No Tour exists")
    else:
        print("Tour: ", path)

if __name__ == "__main__":
    N = int(input("Enter the value of N: "))
    row, col = map(int, input("Enter the starting position (row, col): ").split())
    solve(N, row, col)

In this code, we use the A* Search algorithm to find the shortest path from the start position to all other positions on the chessboard. The `heuristic` function is used to estimate the cost to reach the goal from a given state. The `astar` function uses a priority queue to find the next node to visit, with the cost of the path so far plus a heuristic estimate. The `solve` function reads the input and calls the `astar` function to find the knight's tour.