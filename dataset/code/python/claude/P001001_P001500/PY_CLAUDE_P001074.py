
import heapq
n,m,s=map(int,input().split())
adj=[[] for _ in range(n+1)]
for _ in range(m):
    u,v,w=map(int,input().split());adj[u].append((v,w))
dist=[float('inf')]*(n+1);dist[s]=0
h=[(0,s)]
while h:
    d,u=heapq.heappop(h)
    if d>dist[u]: continue
    for v,w in adj[u]:
        if dist[u]+w<dist[v]: dist[v]=dist[u]+w;heapq.heappush(h,(dist[v],v))
print(*[dist[i] if dist[i]!=float('inf') else -1 for i in range(1,n+1)])
