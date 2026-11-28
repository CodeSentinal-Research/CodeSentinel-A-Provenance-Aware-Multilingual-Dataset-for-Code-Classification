
from collections import deque
n,m,s=map(int,input().split())
adj=[[] for _ in range(n+1)]
for _ in range(m):
    u,v=map(int,input().split());adj[u].append(v);adj[v].append(u)
visited={s};q=deque([s])
while q:
    node=q.popleft()
    for nb in adj[node]:
        if nb not in visited: visited.add(nb);q.append(nb)
print(len(visited))
