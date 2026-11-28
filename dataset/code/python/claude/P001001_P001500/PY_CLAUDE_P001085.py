
from collections import deque
n,m,s,t=map(int,input().split())
adj=[[] for _ in range(n+1)]
for _ in range(m):
    u,v=map(int,input().split());adj[u].append(v)
dp=[0]*(n+1);dp[s]=1
topo=[]
indeg=[0]*(n+1)
for u in range(1,n+1):
    for v in adj[u]: indeg[v]+=1
q=deque(i for i in range(1,n+1) if indeg[i]==0)
while q:
    u=q.popleft();topo.append(u)
    for v in adj[u]:
        indeg[v]-=1
        if indeg[v]==0: q.append(v)
for u in topo:
    for v in adj[u]: dp[v]=(dp[v]+dp[u])
print(dp[t])
