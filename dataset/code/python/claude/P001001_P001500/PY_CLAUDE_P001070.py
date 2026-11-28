
from collections import deque
n,m=map(int,input().split())
adj=[[] for _ in range(n+1)]
for _ in range(m):
    u,v=map(int,input().split());adj[u].append(v);adj[v].append(u)
color=[-1]*(n+1)
def bfs(src):
    color[src]=0;q=deque([src])
    while q:
        u=q.popleft()
        for v in adj[u]:
            if color[v]==-1: color[v]=1-color[u];q.append(v)
            elif color[v]==color[u]: return False
    return True
for i in range(1,n+1):
    if color[i]==-1 and not bfs(i): print('false');exit()
print('true')
