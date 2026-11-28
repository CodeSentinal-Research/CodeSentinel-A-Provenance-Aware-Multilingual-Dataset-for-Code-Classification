# problem title : Rat in a Maze
# Solve the stated task using standard input and standard output.
from typing import List

def find_paths(maze: List[List[int]]) -> List[str]:
    n = len(maze)
    if maze[0][0] == 0 or maze[n - 1][n - 1] == 0:
        return []

    visited = [[False] * n for _ in range(n)]
    res = []

    def backtrack(r: int, c: int, path: str):
        if r == n - 1 and c == n - 1:
            res.append(path)
            return

        visited[r][c] = True
        for dr, dc, d in [(1, 0, 'D'), (0, -1, 'L'), (0, 1, 'R'), (-1, 0, 'U')]:
            nr, nc = r + dr, c + dc
            if 0 <= nr < n and 0 <= nc < n and not visited[nr][nc] and maze[nr][nc] == 1:
                backtrack(nr, nc, path + d)
        visited[r][c] = False

    backtrack(0, 0, "")
    return res

if __name__ == '__main__':
    n = int(input())
    maze = [list(map(int, input().split())) for _ in range(n)]
    paths = find_paths(maze)
    print(" ".join(paths) if paths else "-1")
