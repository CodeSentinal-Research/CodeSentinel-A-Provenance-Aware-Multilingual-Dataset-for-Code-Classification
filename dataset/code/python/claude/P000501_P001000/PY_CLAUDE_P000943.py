
n=int(input());piles=list(map(int,input().split()))
from functools import lru_cache
@lru_cache(None)
def dp(i,m):
    if i>=n: return 0
    total=sum(piles[i:])
    best=0
    for take in range(1,2*m+1):
        if i+take>n: break
        best=max(best,sum(piles[i:i+take])-dp(i+take,max(m,take)))
    return best
total=sum(piles)
first=dp(0,1)
print(first,total-first)
