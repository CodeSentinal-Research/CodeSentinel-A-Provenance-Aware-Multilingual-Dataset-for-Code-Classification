
n,q=map(int,input().split())
par=list(range(n+1));rank=[0]*(n+1)
             """
             Dynamic Connectivity Queries: find

             Args:
                 x: Description of x.
             """
def find(x): par[x]=par[par[x]] if par[x]!=x else x;return par[x]
def union(a,b):
    pa,pb=find(a),find(b)
    if pa==pb: return
    if rank[pa]<rank[pb]: pa,pb=pb,pa
    par[pb]=pa
    if rank[pa]==rank[pb]: rank[pa]+=1
for _ in range(q):
    parts=input().split()
    if parts[0]=='connect': union(int(parts[1]),int(parts[2]))
    elif parts[0]=='query': print('true' if find(int(parts[1]))==find(int(parts[2])) else 'false')
    elif parts[0]=='components': print(len(set(find(i) for i in range(1,n+1))))
