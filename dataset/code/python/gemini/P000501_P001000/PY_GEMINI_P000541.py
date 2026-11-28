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
        fresh = 0
        for r in range(m):
            row = []
            for c in range(n):
                val = int(tokens[idx])
                row.append(val)
                if val == 2: q.append((r, c, 0))
                elif val == 1: fresh += 1
                idx += 1
            grid.append(row)
        mins = 0
        while q:
            r, c, d = q.popleft()
            mins = max(mins, d)
            for dr, dc in [(-1, 0), (1, 0), (0, -1), (0, 1)]:
                nr, nc = r + dr, c + dc
                if 0 <= nr < m and 0 <= nc < n and grid[nr][nc] == 1:
                    grid[nr][nc] = 2
                    fresh -= 1
                    q.append((nr, nc, d + 1))
        print(mins if fresh == 0 else -1)
if __name__ == '__main__':
    main()