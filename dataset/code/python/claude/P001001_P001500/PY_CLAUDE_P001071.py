
n,m=map(int,input().split())
adj=[[] for _ in range(n+1)]
for _ in range(m):
    u,v=map(int,input().split());adj[u].append(v)
visited=[False]*(n+1);order=[]
def dfs(v):
    visited[v]=True
    for u in adj[v]:
        if not visited[u]: dfs(u)
    order.append(v)
for i in range(1,n+1):
    if not visited[i]: dfs(i)
visited2=[False]*(n+1)
def dfs2(v):
    visited2[v]=True
    for u in adj[v]:
        if not visited2[u]: dfs2(u)

radj=[[] for _ in range(n+1)]
for u in range(1,n+1):
    for v in adj[u]: radj[v].append(u)
for v in reversed(order):
    if not visited2[v]:
        dfs2(v)
        if all(visited2[i] for i in range(1,n+1)): print(v);exit()
print(-1)
