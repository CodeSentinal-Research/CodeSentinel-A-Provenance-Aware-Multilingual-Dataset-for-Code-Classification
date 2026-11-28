
n,m=map(int,input().split())
from collections import defaultdict
adj=defaultdict(list);deg=[0]*(n+1)
for _ in range(m):
    u,v=map(int,input().split());adj[u].append(v);adj[v].append(u);deg[u]+=1;deg[v]+=1
odds=[i for i in range(1,n+1) if deg[i]%2!=0]
if len(odds) not in (0,2): print('No Eulerian Path');exit()
start=odds[0] if odds else 1
stack=[start];path=[]
adj2={i:list(v) for i,v in adj.items()}
while stack:
    v=stack[-1]
    if adj2.get(v): u=adj2[v].pop();adj2[u].remove(v);stack.append(u)
    else: path.append(stack.pop())
print(*reversed(path))
