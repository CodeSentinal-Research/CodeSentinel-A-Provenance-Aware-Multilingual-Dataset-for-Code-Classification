
from collections import deque
n,m,s=map(int,input().split())
adj=[[] for _ in range(n+1)];indeg=[0]*(n+1)
for _ in range(m):
    u,v,w=map(int,input().split());adj[u].append((v,w));indeg[v]+=1
dist=[float('inf')]*(n+1);dist[s]=0
q=deque(i for i in range(1,n+1) if indeg[i]==0)
while q:
    u=q.popleft()
    for v,w in adj[u]:
        if dist[u]+w<dist[v]: dist[v]=dist[u]+w
        indeg[v]-=1
        if indeg[v]==0: q.append(v)
print(*[dist[i] if dist[i]!=float('inf') else -1 for i in range(1,n+1)])
