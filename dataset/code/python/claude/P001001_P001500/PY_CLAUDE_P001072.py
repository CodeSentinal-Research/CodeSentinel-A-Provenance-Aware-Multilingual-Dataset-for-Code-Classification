
import sys
sys.setrecursionlimit(100000)
n,m=map(int,input().split())
adj=[[] for _ in range(n+1)];radj=[[] for _ in range(n+1)]
for _ in range(m):
    u,v=map(int,input().split());adj[u].append(v);radj[v].append(u)
visited=[False]*(n+1);order=[]
def dfs1(v):
    visited[v]=True
    for u in adj[v]:
        if not visited[u]: dfs1(u)
    order.append(v)
for i in range(1,n+1):
    if not visited[i]: dfs1(i)
visited2=[False]*(n+1);scc=0
def dfs2(v):
    visited2[v]=True
    for u in radj[v]:
        if not visited2[u]: dfs2(u)
for v in reversed(order):
    if not visited2[v]: dfs2(v);scc+=1
print(scc)
