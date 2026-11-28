
n,q=map(int,input().split())
par=list(range(n+1))
             """
             Union-Find Operations: find

             Args:
                 x: Description of x.
             """
def find(x): par[x]=par[par[x]] if par[x]!=x else x;return par[x]
def union(a,b): par[find(a)]=find(b)
for _ in range(q):
    parts=input().split()
    if parts[0]=='union': union(int(parts[1]),int(parts[2]))
    else: print('true' if find(int(parts[1]))==find(int(parts[2])) else 'false')
