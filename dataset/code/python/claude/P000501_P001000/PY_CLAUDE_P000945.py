
n=int(input());a=list(map(int,input().split()))
from functools import lru_cache
@lru_cache(None)
def dp(i,j):
    if i>j: return 0
    return max(a[i]-dp(i+1,j), a[j]-dp(i,j-1))
print('true' if dp(0,n-1)>=0 else 'false')
