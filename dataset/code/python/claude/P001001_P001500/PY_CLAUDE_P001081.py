
n,m=map(int,input().split())
from collections import defaultdict
adj=defaultdict(list)
deg=[0]*(n+1)
for _ in range(m):
    u,v=map(int,input().split());adj[u].append(v);adj[v].append(u);deg[u]+=1;deg[v]+=1
if any(d%2!=0 for d in deg[1:]): print('No Eulerian Circuit');exit()

stack=[1];path=[]
adj2={i:list(v) for i,v in adj.items()}
while stack:
    v=stack[-1]
    if adj2.get(v):
        u=adj2[v].pop();adj2[u].remove(v);stack.append(u)
    else: path.append(stack.pop())
print(*reversed(path))
