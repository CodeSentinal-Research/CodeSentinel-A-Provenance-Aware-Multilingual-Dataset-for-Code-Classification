
n,m=map(int,input().split())
adj=[[] for _ in range(n+1)]
for _ in range(m):
    u,v=map(int,input().split());adj[u].append(v);adj[v].append(u)
disc=[-1]*(n+1);low=[-1]*(n+1);parent=[-1]*(n+1);bridges=[];timer=[0]
def dfs(u):
    disc[u]=low[u]=timer[0];timer[0]+=1
    for v in adj[u]:
        if disc[v]==-1:
            parent[v]=u;dfs(v);low[u]=min(low[u],low[v])
            if low[v]>disc[u]: bridges.append((u,v))
        elif v!=parent[u]: low[u]=min(low[u],disc[v])
for i in range(1,n+1):
    if disc[i]==-1: dfs(i)
for u,v in bridges: print(u,v)
