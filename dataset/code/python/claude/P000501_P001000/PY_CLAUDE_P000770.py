
n=int(input());dims=list(map(int,input().split()))
from functools import lru_cache
@lru_cache(None)
def dp(i,j):
    if i==j: return 0
    return min(dp(i,k)+dp(k+1,j)+dims[i-1]*dims[k]*dims[j] for k in range(i,j))
print(dp(1,n-1))
