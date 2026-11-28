
from collections import deque
n,q=map(int,input().split())
adj=[[] for _ in range(n+1)]
for _ in range(n-1):
    u,v=map(int,input().split());adj[u].append(v);adj[v].append(u)
LOG=17;parent=[[0]*(n+1) for _ in range(LOG)];depth=[0]*(n+1)
q2=deque([1]);visited=[False]*(n+1);visited[1]=True
while q2:
    u=q2.popleft()
    for v in adj[u]:
        if not visited[v]: visited[v]=True;parent[0][v]=u;depth[v]=depth[u]+1;q2.append(v)
for k in range(1,LOG):
    for v in range(1,n+1): parent[k][v]=parent[k-1][parent[k-1][v]]
def kth_ancestor(u,k):
    for i in range(LOG):
        if (k>>i)&1: u=parent[i][u]
    return u
for _ in range(q):
    u,k=map(int,input().split());print(kth_ancestor(u,k))
