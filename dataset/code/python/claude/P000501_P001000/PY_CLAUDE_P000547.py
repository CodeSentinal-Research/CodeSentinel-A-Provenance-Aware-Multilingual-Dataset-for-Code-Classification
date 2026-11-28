
from collections import deque
m,n=map(int,input().split());grid=[list(input().split()) for _ in range(m)]
fire_time=[[float('inf')]*n for _ in range(m)]
q=deque()
for i in range(m):
    for j in range(n):
        if grid[i][j]=='F': fire_time[i][j]=0;q.append((i,j,0))
while q:
    r,c,t=q.popleft()
    for dr,dc in [(-1,0),(1,0),(0,-1),(0,1)]:
        nr,nc=r+dr,c+dc
        if 0<=nr<m and 0<=nc<n and grid[nr][nc]!='#' and fire_time[nr][nc]==float('inf'):
            fire_time[nr][nc]=t+1;q.append((nr,nc,t+1))
def canEscape(stay):
    q2=deque([(0,0,stay)])
    visited={(0,0)}
    while q2:
        r,c,t=q2.popleft()
        for dr,dc in [(-1,0),(1,0),(0,-1),(0,1)]:
            nr,nc=r+dr,c+dc
            if 0<=nr<m and 0<=nc<n and grid[nr][nc]!='#' and (nr,nc) not in visited:
                if nr==m-1 and nc==n-1 and t+1<=fire_time[nr][nc]: return True
                if t+1<fire_time[nr][nc]: visited.add((nr,nc));q2.append((nr,nc,t+1))
    return False
lo,hi=0,m*n
if not canEscape(hi): print(-1)
else:
    while lo<hi:
        mid=(lo+hi+1)//2
        if canEscape(mid): lo=mid
        else: hi=mid-1
    print(lo)
