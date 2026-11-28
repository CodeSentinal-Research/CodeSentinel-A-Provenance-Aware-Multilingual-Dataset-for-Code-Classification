Here is the Python code for the problem:

from typing import List
import sys
import heapq

def cut_off_trees(forest: List[List[int]]) -> int:
    m, n = len(forest), len(forest[0])
    heights = [[sys.maxsize] * n for _ in range(m)]
    visited = [[False] * n for _ in range(m)]

    def bfs(sr, sc, height):
        q = [(sr, sc, 0)]
        visited[sr][sc] = True
        while q:
            r, c, steps = heapq.heappop(q)
            if r == m - 1 and c == n - 1:
                return steps
            for nr,nc in [(r-1,c), (r+1,c), (r,c-1), (r,c+1)]:
                if 0 <= nr < m and 0 <= nc < n and not visited[nr][nc] and forest[nr][nc] < heights[nr][nc]:
                    visited[nr][nc] = True
                    heapq.heappush(q, (nr, nc, steps + 1))
                    heights[nr][nc] = forest[nr][nc]

    for r in range(m):
        for c in range(n):
            if forest[r][c] == 1:
                heights[r][c] = 0
                return -1 if bfs(r, c, 0) == -1 else heights[r][c]

    return -1

This code firstly finds the starting point of the tree, and then perform a Breadth-First Search (BFS) from there. BFS is performed only if the current cell can be reached from the starting point. If a cell cannot be reached, it is marked as not reachable. The number of steps from the starting point to reach the current cell is calculated and added to the queue. The height of the current cell is updated. The process is repeated until all trees have been visited.

The main function is as follows:

def main():
    m = 5
    n = 5
    forest = [[1, 0, 1, 1, 0], [1, 0, 0, 1, 1], [1, 1, 0, 0, 1], [0, 1, 1, 1, 0], [0, 0, 0, 0, 0]]
    print(cut_off_trees(forest))

if __name__ == "__main__":
    main()

This main function first creates a test case with the given dimensions (5x5), and then it prints the result of calling the `cut_off_trees` function with this test case as input.