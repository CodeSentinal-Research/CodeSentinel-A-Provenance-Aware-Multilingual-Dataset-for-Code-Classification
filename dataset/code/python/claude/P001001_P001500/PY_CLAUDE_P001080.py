
n,m=map(int,input().split())
adj=[[] for _ in range(n+1)]
for _ in range(m):
    u,v=map(int,input().split());adj[u].append(v);adj[v].append(u)
disc=[-1]*(n+1);low=[-1]*(n+1);parent=[-1]*(n+1);ap=set();timer=[0]
def dfs(u):
    disc[u]=low[u]=timer[0];timer[0]+=1;children=0
    for v in adj[u]:
        if disc[v]==-1:
            children+=1;parent[v]=u;dfs(v);low[u]=min(low[u],low[v])
            if parent[u]==-1 and children>1: ap.add(u)
            if parent[u]!=-1 and low[v]>=disc[u]: ap.add(u)
        elif v!=parent[u]: low[u]=min(low[u],disc[v])
for i in range(1,n+1):
    if disc[i]==-1: dfs(i)
print(*sorted(ap))
