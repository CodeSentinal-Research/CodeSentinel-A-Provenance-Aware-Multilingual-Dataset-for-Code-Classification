
from collections import deque
m,n=map(int,input().split());grid=[list(map(int,input().split())) for _ in range(m)]
INF=2147483647;q=deque()
for i in range(m):
    for j in range(n):
        if grid[i][j]==0: q.append((i,j))
while q:
    r,c=q.popleft()
    for dr,dc in [(-1,0),(1,0),(0,-1),(0,1)]:
        nr,nc=r+dr,c+dc
        if 0<=nr<m and 0<=nc<n and grid[nr][nc]==INF:
            grid[nr][nc]=grid[r][c]+1;q.append((nr,nc))
for row in grid: print(*row)
