
n,m=map(int,input().split());grid=[list(map(int,input().split())) for _ in range(n)]
MOD=10**9+7
from functools import lru_cache
@lru_cache(None)
def dp(r,c):
    if r==n-1 and c==m-1: return 1
    res=0
    for dr,dc in [(1,0),(0,1)]:
        nr,nc=r+dr,c+dc
        if 0<=nr<n and 0<=nc<m and grid[nr][nc]==0: res=(res+dp(nr,nc))%MOD
    return res
print(0 if grid[0][0] or grid[n-1][m-1] else dp(0,0))
