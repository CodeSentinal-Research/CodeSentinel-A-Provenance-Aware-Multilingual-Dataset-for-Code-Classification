
n,m,q=map(int,input().split())
edges=set()
for _ in range(m):
    u,v=map(int,input().split());edges.add((u,v))
for _ in range(q):
    u,v=map(int,input().split())
    print('true' if (u,v) in edges else 'false')
