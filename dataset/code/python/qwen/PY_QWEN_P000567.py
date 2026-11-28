import sys
from collections import deque
def solve():
    input_data = sys.stdin.read().split()
    if not input_data: return
    m = int(input_data[0])
    n = int(input_data[1])
    grid = []
    idx = 2
    trees = []
    for i in range(m):
        row = list(map(int, input_data[idx:idx+n]))
        grid.append(row)
        idx += n
        for j in range(n):
            if row[j] > 1:
                trees.append((row[j], i, j))
    trees.sort()
    def bfs(sr, sc, tr, tc):
        if sr == tr and sc == tc: return 0
        q = deque([(sr, sc, 0)])
        vis = {(sr, sc)}
        while q:
            x, y, d = q.popleft()
            for dx, dy in [(-1,0),(1,0),(0,-1),(0,1)]:
                nx, ny = x + dx, y + dy
                if 0 <= nx < m and 0 <= ny < n and grid[nx][ny] != 0 and (nx, ny) not in vis:
                    if nx == tr and ny == tc: return d + 1
                    vis.add((nx, ny))
                    q.append((nx, ny, d + 1))
        return -1
    ans = 0
    sr, sc = 0, 0
    for _, tr, tc in trees:
        d = bfs(sr, sc, tr, tc)
        if d == -1:
            print(-1)
            return
        ans += d
        sr, sc = tr, tc
    print(ans)
solve()
