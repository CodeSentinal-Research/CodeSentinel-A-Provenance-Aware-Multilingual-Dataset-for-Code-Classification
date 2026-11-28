
from collections import deque
m,n=map(int,input().split());grid=[list(map(int,input().split())) for _ in range(m)]
q=deque();fresh=0
for i in range(m):
    for j in range(n):
        if grid[i][j]==2: q.append((i,j,0))
        elif grid[i][j]==1: fresh+=1
time=0
while q:
    r,c,t=q.popleft()
    for dr,dc in [(-1,0),(1,0),(0,-1),(0,1)]:
        nr,nc=r+dr,c+dc
        if 0<=nr<m and 0<=nc<n and grid[nr][nc]==1:
            grid[nr][nc]=2;fresh-=1;time=t+1;q.append((nr,nc,t+1))
print(-1 if fresh>0 else time)
