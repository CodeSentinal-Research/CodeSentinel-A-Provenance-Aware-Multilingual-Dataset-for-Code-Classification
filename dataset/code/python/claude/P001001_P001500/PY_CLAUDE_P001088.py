
from collections import deque
n,m,s,k=map(int,input().split())
adj=[[] for _ in range(n+1)]
for _ in range(m):
    u,v=map(int,input().split());adj[u].append(v);adj[v].append(u)
dist=[-1]*(n+1);dist[s]=0;q=deque([s])
while q:
    u=q.popleft()
    for v in adj[u]:
        if dist[v]==-1: dist[v]=dist[u]+1;q.append(v)
print(sum(1 for d in dist[1:] if d==k))
