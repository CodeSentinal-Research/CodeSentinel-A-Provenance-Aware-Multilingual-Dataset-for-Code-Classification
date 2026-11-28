
n,m=map(int,input().split())
INF=float('inf')
dist=[[INF]*(n+1) for _ in range(n+1)]
for i in range(1,n+1): dist[i][i]=0
for _ in range(m):
    u,v,w=map(int,input().split());dist[u][v]=min(dist[u][v],w)
for k in range(1,n+1):
    for i in range(1,n+1):
        for j in range(1,n+1):
            if dist[i][k]+dist[k][j]<dist[i][j]: dist[i][j]=dist[i][k]+dist[k][j]
for i in range(1,n+1): print(*[dist[i][j] if dist[i][j]!=INF else -1 for j in range(1,n+1)])
