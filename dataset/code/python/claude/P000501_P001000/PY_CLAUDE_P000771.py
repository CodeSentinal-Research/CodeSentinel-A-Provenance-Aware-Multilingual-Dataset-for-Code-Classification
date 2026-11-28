
n=int(input());keys=list(map(int,input().split()));freq=list(map(int,input().split()))
from functools import lru_cache
pre=[0]*(n+1)
for i in range(n): pre[i+1]=pre[i]+freq[i]
@lru_cache(None)
def dp(i,j):
    if i>j: return 0
    total=pre[j+1]-pre[i]
    return min(dp(i,k-1)+dp(k+1,j)+total for k in range(i,j+1))
print(dp(0,n-1))
