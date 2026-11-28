
from collections import deque
n,m=map(int,input().split())
adj=[[] for _ in range(n+1)]
for _ in range(m):
    u,v=map(int,input().split());adj[u].append(v);adj[v].append(u)
if m!=n-1: print('false');exit()
visited={1};q=deque([1])
while q:
    u=q.popleft()
    for v in adj[u]:
        if v not in visited: visited.add(v);q.append(v)
print('true' if len(visited)==n else 'false')
