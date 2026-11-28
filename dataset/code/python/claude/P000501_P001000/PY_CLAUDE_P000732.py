
n=int(input());grid=[list(map(int,input().split())) for _ in range(n)]
res=[]
def dfs(r,c,path,vis):
    if r==n-1 and c==n-1: res.append(path);return
    for dr,dc,d in [(-1,0,'U'),(1,0,'D'),(0,-1,'L'),(0,1,'R')]:
        nr,nc=r+dr,c+dc
        if 0<=nr<n and 0<=nc<n and grid[nr][nc]==1 and (nr,nc) not in vis:
            vis.add((nr,nc));dfs(nr,nc,path+d,vis);vis.remove((nr,nc))
if grid[0][0]: dfs(0,0,'',(set([(0,0)])))
if res:
    for p in sorted(res): print(p)
else: print(-1)
