
l,r,m=map(int,input().split())
adj=[[] for _ in range(l+r+1)]
for _ in range(m):
    u,v=map(int,input().split());adj[u].append(l+v)
match_l=[-1]*(l+1);match_r=[-1]*(r+1)
def dfs(u,visited):
    for v in adj[u]:
        rv=v-l
        if rv not in visited:
            visited.add(rv)
            if match_r[rv]==-1 or dfs(match_r[rv],visited):
                match_l[u]=rv;match_r[rv]=u;return True
    return False
res=0
for u in range(1,l+1):
    if match_l[u]==-1:
        if dfs(u,set()): res+=1
print(res)
