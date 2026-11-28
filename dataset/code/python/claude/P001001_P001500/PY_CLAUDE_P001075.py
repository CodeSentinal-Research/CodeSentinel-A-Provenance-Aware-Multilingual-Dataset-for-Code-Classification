
n,m,s=map(int,input().split())
edges=[]
for _ in range(m):
    u,v,w=map(int,input().split());edges.append((u,v,w))
dist=[float('inf')]*(n+1);dist[s]=0
for _ in range(n-1):
    for u,v,w in edges:
        if dist[u]!=float('inf') and dist[u]+w<dist[v]: dist[v]=dist[u]+w

neg_cycle=False
for u,v,w in edges:
    if dist[u]!=float('inf') and dist[u]+w<dist[v]: neg_cycle=True;break
if neg_cycle: print('Negative cycle detected')
else: print(*[dist[i] if dist[i]!=float('inf') else -1 for i in range(1,n+1)])
