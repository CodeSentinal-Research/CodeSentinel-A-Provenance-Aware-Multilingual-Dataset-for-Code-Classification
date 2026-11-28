
v=int(input());e=int(input());edges=[tuple(map(int,input().split())) for _ in range(e)];m=int(input())
adj=[[] for _ in range(v+1)]
for a,b in edges: adj[a].append(b);adj[b].append(a)
color=[0]*(v+1)
def ok(node,c):
    return all(color[nb]!=c for nb in adj[node])
def solve(node):
    if node==v+1: return True
    for c in range(1,m+1):
        if ok(node,c):
            color[node]=c
            if solve(node+1): return True
            color[node]=0
    return False
print('true' if solve(1) else 'false')
