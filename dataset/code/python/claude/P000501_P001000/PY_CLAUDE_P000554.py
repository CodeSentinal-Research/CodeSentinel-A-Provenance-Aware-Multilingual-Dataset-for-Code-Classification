
from collections import deque
m,n=map(int,input().split());maze=[list(input()) for _ in range(m)]
er,ec=map(int,input().split())
maze[er][ec]='X';q=deque([(er,ec,0)])
while q:
    r,c,d=q.popleft()
    for dr,dc in [(-1,0),(1,0),(0,-1),(0,1)]:
        nr,nc=r+dr,c+dc
        if 0<=nr<m and 0<=nc<n and maze[nr][nc]=='.':
            if nr==0 or nr==m-1 or nc==0 or nc==n-1: print(d+1);exit()
            maze[nr][nc]='X';q.append((nr,nc,d+1))
print(-1)
