
n=int(input())
from functools import lru_cache
@lru_cache(None)
def count(lo,hi):
    if lo>hi: return 1
    return sum(count(lo,k-1)*count(k+1,hi) for k in range(lo,hi+1))
print(count(1,n))
