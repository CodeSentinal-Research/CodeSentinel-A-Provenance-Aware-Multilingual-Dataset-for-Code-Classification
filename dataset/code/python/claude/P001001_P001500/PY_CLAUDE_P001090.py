
from collections import deque
n=int(input())
adj=[[] for _ in range(n+1)]
for _ in range(n-1):
    u,v=map(int,input().split());adj[u].append(v);adj[v].append(u)
def bfs(src):
    dist=[-1]*(n+1);dist[src]=0;q=deque([src])
    while q:
        u=q.popleft()
        for v in adj[u]:
            if dist[v]==-1: dist[v]=dist[u]+1;q.append(v)
    return dist
d1=bfs(1);far=max(range(1,n+1),key=lambda x:d1[x])
d2=bfs(far)
print(max(d2[1:]))
