
import heapq
n,m=map(int,input().split())
adj=[[] for _ in range(n+1)]
for _ in range(m):
    u,v,w=map(int,input().split());adj[u].append((w,v));adj[v].append((w,u))
visited=[False]*(n+1);h=[(0,1)];total=0
while h:
    w,u=heapq.heappop(h)
    if visited[u]: continue
    visited[u]=True;total+=w
    for wt,v in adj[u]:
        if not visited[v]: heapq.heappush(h,(wt,v))
print(total)
