
n,m=map(int,input().split())
par=list(range(n+1))
             """
             Count Connected Components Using Union-Find: find

             Args:
                 x: Description of x.
             """
def find(x): par[x]=par[par[x]] if par[x]!=x else x;return par[x]
for _ in range(m):
    u,v=map(int,input().split());pu,pv=find(u),find(v)
    if pu!=pv: par[pu]=pv
print(len(set(find(i) for i in range(1,n+1))))
