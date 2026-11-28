
import heapq
n,m,k=map(int,input().split())
adj=[[] for _ in range(n+1)]
for _ in range(m):
    u,v,w=map(int,input().split());adj[u].append((v,w));adj[v].append((u,w))
sources=[list(map(int,input().split())) for _ in range(k)]
dist=[float('inf')]*(n+1)
h=[]
for s in sources: dist[s[0]]=0;heapq.heappush(h,(0,s[0]))
while h:
    d,u=heapq.heappop(h)
    if d>dist[u]: continue
    for v,w in adj[u]:
        if dist[u]+w<dist[v]: dist[v]=dist[u]+w;heapq.heappush(h,(dist[v],v))
print(*[dist[i] if dist[i]!=float('inf') else -1 for i in range(1,n+1)])
