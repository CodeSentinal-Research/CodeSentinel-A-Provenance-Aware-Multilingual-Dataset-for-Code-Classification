
n,m=map(int,input().split())
indeg=[0]*(n+1)
for _ in range(m):
    u,v=map(int,input().split());indeg[v]+=1
print(sum(1 for i in range(1,n+1) if indeg[i]==0))
