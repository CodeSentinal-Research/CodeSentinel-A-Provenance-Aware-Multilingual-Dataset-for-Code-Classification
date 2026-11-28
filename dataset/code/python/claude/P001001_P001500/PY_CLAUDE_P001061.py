
n,m=map(int,input().split())
adj=[[] for _ in range(n+1)]
for _ in range(m):
    u,v=map(int,input().split());adj[u].append(v)
color=[0]*(n+1)
def dfs(v,c):
    color[v]=c
    for u in adj[v]:
        if color[u]==0:
            if dfs(u,c+1): return True
        elif color[u]==c: return True
    return False
for i in range(1,n+1):
    if color[i]==0 and dfs(i,1): print('true');exit()
print('false')
