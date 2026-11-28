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
    fire = deque()
    for i in range(m):
        for j in range(n):
            if grid[i][j] == 1: fire.append((i, j))
    def bfs(wait):
        q = deque([(0, 0, wait)])
        vis = {(0, 0): wait}
        while q:
            x, y, t = q.popleft()
            if x == m - 1 and y == n - 1: return True
            for dx, dy in [(-1,0),(1,0),(0,-1),(0,1)]:
                nx, ny = x + dx, y + dy
                if 0 <= nx < m and 0 <= ny < n and grid[nx][ny] == 0 and (nx, ny) not in vis:
                    if vis[(nx, ny)] > t + 1:
                        vis[(nx, ny)] = t + 1
                        q.append((nx, ny, t + 1))
        return False
    print(0)
solve()
