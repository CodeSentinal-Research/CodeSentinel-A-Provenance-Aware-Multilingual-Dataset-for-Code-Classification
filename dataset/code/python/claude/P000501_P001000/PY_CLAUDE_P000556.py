
from collections import deque
from sortedcontainers import SortedList
m,n=map(int,input().split());grid=[list(map(int,input().split())) for _ in range(m)]
dist=[[-1]*n for _ in range(m)];dist[0][0]=1
row_sets=[SortedList(range(n)) for _ in range(m)]
col_sets=[SortedList(range(m)) for _ in range(n)]
row_sets[0].discard(0);col_sets[0].discard(0);q=deque([(0,0)])
while q:
    r,c=q.popleft();d=dist[r][c]
    g=grid[r][c]

    lst=row_sets[r];i=lst.bisect_left(c+1)
    while i<len(lst) and lst[i]<=c+g:
        nc=lst[i];dist[r][nc]=d+1
        if r==m-1 and nc==n-1: print(d+1);exit()
        q.append((r,nc));col_sets[nc].discard(r);lst.remove(nc)

    lst=col_sets[c];i=lst.bisect_left(r+1)
    while i<len(lst) and lst[i]<=r+g:
        nr=lst[i];dist[nr][c]=d+1
        if nr==m-1 and c==n-1: print(d+1);exit()
        q.append((nr,c));row_sets[nr].discard(c);lst.remove(nr)
print(-1)
