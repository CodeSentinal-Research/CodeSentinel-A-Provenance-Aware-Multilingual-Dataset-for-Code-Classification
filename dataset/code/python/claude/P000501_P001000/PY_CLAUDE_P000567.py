
from collections import deque
m,n=map(int,input().split());grid=[list(map(int,input().split())) for _ in range(m)]
trees=sorted((grid[i][j],i,j) for i in range(m) for j in range(n) if grid[i][j]>1)
def bfs(sr,sc,er,ec):
    if sr==er and sc==ec: return 0
    vis=[[False]*n for _ in range(m)];vis[sr][sc]=True;q=deque([(sr,sc,0)])
    while q:
        r,c,d=q.popleft()
        for dr,dc in [(-1,0),(1,0),(0,-1),(0,1)]:
            nr,nc=r+dr,c+dc
            if 0<=nr<m and 0<=nc<n and not vis[nr][nc] and grid[nr][nc]:
                if nr==er and nc==ec: return d+1
                vis[nr][nc]=True;q.append((nr,nc,d+1))
    return -1
steps=0;cr,cc=0,0
for _,tr,tc in trees:
    d=bfs(cr,cc,tr,tc)
    if d==-1: print(-1);exit()
    steps+=d;cr,cc=tr,tc
print(steps)
