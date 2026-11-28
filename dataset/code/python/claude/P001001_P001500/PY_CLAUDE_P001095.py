
from collections import deque
n,m,s,t=map(int,input().split())
cap=[[0]*(n+1) for _ in range(n+1)]
adj=[[] for _ in range(n+1)]
for _ in range(m):
    u,v,w=map(int,input().split());cap[u][v]+=w;adj[u].append(v);adj[v].append(u)
def bfs():
    """
    Maximum Flow: bfs
    """
    parent=[-1]*(n+1);parent[s]=s;q=deque([s])
    while q:
        u=q.popleft()
        for v in adj[u]:
            if parent[v]==-1 and cap[u][v]>0: parent[v]=u;q.append(v)
    return parent[t]!=-1,parent
flow=0
while True:
    found,parent=bfs()
    if not found: break
    path_flow=float('inf');v=t
    while v!=s: u=parent[v];path_flow=min(path_flow,cap[u][v]);v=u
    v=t
    while v!=s: u=parent[v];cap[u][v]-=path_flow;cap[v][u]+=path_flow;v=u
    flow+=path_flow
print(flow)
