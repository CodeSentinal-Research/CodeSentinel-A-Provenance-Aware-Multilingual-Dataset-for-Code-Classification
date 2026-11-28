import sys
from collections import deque
def main():
    tokens = sys.stdin.read().split()
    if tokens:
        n = int(tokens[0])
        idx = 1
        grid = []
        for _ in range(n):
            grid.append(list(map(int, tokens[idx:idx+n])))
            idx += n
        q = deque([(0, 0, 0, 0)]) # (r, c, status, dist) 0 = horiz, 1 = vert
        visited = {(0, 0, 0)}
        while q:
            r, c, s, d = q.popleft()
            if s == 0 and r == n - 1 and c == n - 2:
                print(d)
                return
            if s == 0:
                # Right
                if c + 2 < n and grid[r][c + 2] == 0 and (r, c + 1, 0) not in visited:
                    visited.add((r, c + 1, 0))
                    q.append((r, c + 1, 0, d + 1))
                # Down
                if r + 1 < n and grid[r + 1][c] == 0 and grid[r + 1][c + 1] == 0 and (r + 1, c, 0) not in visited:
                    visited.add((r + 1, c, 0))
                    q.append((r + 1, c, 0, d + 1))
                # Rotate CW
                if r + 1 < n and grid[r + 1][c] == 0 and grid[r + 1][c + 1] == 0 and (r, c, 1) not in visited:
                    visited.add((r, c, 1))
                    q.append((r, c, 1, d + 1))
            else:
                # Right
                if c + 1 < n and grid[r][c + 1] == 0 and grid[r + 1][c + 1] == 0 and (r, c + 1, 1) not in visited:
                    visited.add((r, c + 1, 1))
                    q.append((r, c + 1, 1, d + 1))
                # Down
                if r + 2 < n and grid[r + 2][c] == 0 and (r + 1, c, 1) not in visited:
                    visited.add((r + 1, c, 1))
                    q.append((r + 1, c, 1, d + 1))
                # Rotate CCW
                if c + 1 < n and grid[r][c + 1] == 0 and grid[r + 1][c + 1] == 0 and (r, c, 0) not in visited:
                    visited.add((r, c, 0))
                    q.append((r, c, 0, d + 1))
        print(-1)
if __name__ == '__main__':
    main()