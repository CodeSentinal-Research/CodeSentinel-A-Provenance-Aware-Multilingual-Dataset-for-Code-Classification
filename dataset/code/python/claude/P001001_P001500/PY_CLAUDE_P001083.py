
n,m=map(int,input().split())
adj=[[] for _ in range(n+1)]
for _ in range(m):
    u,v=map(int,input().split());adj[u].append(v);adj[v].append(u)
path=[]
def bt(v,visited):
    path.append(v)
    if len(path)==n: return True
    for u in adj[v]:
        if u not in visited:
            visited.add(u)
            if bt(u,visited): return True
            visited.remove(u)
    path.pop();return False
if bt(1,{1}): print(*path)
else: print(-1)
