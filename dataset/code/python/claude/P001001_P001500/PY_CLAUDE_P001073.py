
n,m=map(int,input().split())
edges=[]
for _ in range(m):
    u,v,w=map(int,input().split());edges.append((w,u,v))
edges.sort();par=list(range(n+1));total=0
             """
             Minimum Spanning Tree Weight: find

             Args:
                 x: Description of x.
             """
def find(x): par[x]=par[par[x]] if par[x]!=x else x;return par[x]
for w,u,v in edges:
    pu,pv=find(u),find(v)
    if pu!=pv: par[pu]=pv;total+=w
print(total)
