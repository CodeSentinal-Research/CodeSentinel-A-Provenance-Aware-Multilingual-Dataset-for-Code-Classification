
import heapq
n,k=map(int,input().split());mat=[list(map(int,input().split())) for _ in range(n)]
h=[(mat[0][0],0,0)];visited=set([(0,0)])
for _ in range(k):
    v,r,c=heapq.heappop(h)
    for dr,dc in [(0,1),(1,0)]:
        nr,nc=r+dr,c+dc
        if 0<=nr<n and 0<=nc<n and (nr,nc) not in visited:
            visited.add((nr,nc));heapq.heappush(h,(mat[nr][nc],nr,nc))
print(v)
