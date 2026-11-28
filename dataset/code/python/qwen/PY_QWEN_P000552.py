import sys
from collections import deque
def solve():
    input_data = sys.stdin.read().split()
    if not input_data: return
    m = int(input_data[0])
    n = int(input_data[1])
    grid = []
    idx = 2
    for _ in range(m):
        grid.append(list(map(int, input_data[idx:idx+n])))
        idx += n
    q = deque()
    for i in range(m):
        for j in range(n):
            if grid[i][j] == 0: q.append((i, j))
    while q:
        x, y = q.popleft()
        for dx, dy in [(-1,0),(1,0),(0,-1),(0,1)]:
            nx, ny = x + dx, y + dy
            if 0 <= nx < m and 0 <= ny < n and grid[nx][ny] == 2147483647:
                grid[nx][ny] = grid[x][y] + 1
                q.append((nx, ny))
    for row in grid:
        print(" ".join(map(str, row)))
solve()
