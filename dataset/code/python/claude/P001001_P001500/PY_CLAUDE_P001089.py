
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
d1=bfs(1);far1=max(range(1,n+1),key=lambda x:d1[x])
d2=bfs(far1);far2=max(range(1,n+1),key=lambda x:d2[x])
d3=bfs(far2)

path=[];cur=far2
while cur!=far1:
    path.append(cur)
    for v in adj[cur]:
        if d3[v]==d3[cur]-1: cur=v;break
path.append(far1)
mid=len(path)//2
print(path[mid])
