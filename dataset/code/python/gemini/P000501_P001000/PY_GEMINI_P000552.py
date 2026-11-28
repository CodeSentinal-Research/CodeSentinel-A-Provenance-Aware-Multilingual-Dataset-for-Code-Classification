import sys
from collections import deque
def main():
    tokens = sys.stdin.read().split()
    if tokens:
        m = int(tokens[0])
        n = int(tokens[1])
        idx = 2
        grid = []
        q = deque()
        for r in range(m):
            row = []
            for c in range(n):
                val = int(tokens[idx])
                row.append(val)
                if val == 0: q.append((r, c, 0))
                idx += 1
            grid.append(row)
        dirs = [(-1, 0), (1, 0), (0, -1), (0, 1)]
        while q:
            r, c, d = q.popleft()
            for dr, dc in dirs:
                nr, nc = r + dr, c + dc
                if 0 <= nr < m and 0 <= nc < n and grid[nr][nc] == 2147483647:
                    grid[nr][nc] = d + 1
                    q.append((nr, nc, d + 1))
        for row in grid:
            print(*row)
if __name__ == '__main__':
    main()