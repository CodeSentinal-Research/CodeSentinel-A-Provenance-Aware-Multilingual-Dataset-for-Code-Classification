# problem title : Minimum Number of Visited Cells in a Grid
# Solve the stated task using standard input and standard output.
import sys
from collections import deque
def main():
    tokens = sys.stdin.read().split()
    if tokens:
        m = int(tokens[0])
        n = int(tokens[1])
        idx = 2
        grid = []
        for _ in range(m):
            grid.append(list(map(int, tokens[idx:idx+n])))
            idx += n
        if m == 1 and n == 1:
            print(1)
            return
        dist = [[float('inf')] * n for _ in range(m)]
        dist[0][0] = 1
        # Use simple unvisited rows/cols track
        max_r = [0] * m
        max_c = [0] * n
        q = deque([(0, 0)])
        while q:
            r, c = q.popleft()
            d = dist[r][c]
            k = grid[r][c]
            # explore right
            start_c = max(c + 1, max_r[r] + 1)
            end_c = min(c + k, n - 1)
            for nc in range(start_c, end_c + 1):
                if dist[r][nc] == float('inf'):
                    dist[r][nc] = d + 1
                    if r == m - 1 and nc == n - 1:
                        print(d + 1)
                        return
                    q.append((r, nc))
            max_r[r] = max(max_r[r], end_c)
            # explore down
            start_r = max(r + 1, max_c[c] + 1)
            end_r = min(r + k, m - 1)
            for nr in range(start_r, end_r + 1):
                if dist[nr][c] == float('inf'):
                    dist[nr][c] = d + 1
                    if nr == m - 1 and c == n - 1:
                        print(d + 1)
                        return
                    q.append((nr, c))
            max_c[c] = max(max_c[c], end_r)
        print(dist[m - 1][n - 1] if dist[m - 1][n - 1] != float('inf') else -1)
if __name__ == '__main__':
    main()
