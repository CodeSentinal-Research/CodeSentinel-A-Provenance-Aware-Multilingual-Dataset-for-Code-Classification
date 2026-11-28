
s1,s2=input().strip(),input().strip()
from functools import lru_cache
@lru_cache(None)
def dp(a,b):
    if a==b: return True
    if sorted(a)!=sorted(b): return False
    n=len(a)
    for i in range(1,n):
        if (dp(a[:i],b[:i]) and dp(a[i:],b[i:])) or (dp(a[:i],b[n-i:]) and dp(a[i:],b[:n-i])): return True
    return False
print('true' if dp(s1,s2) else 'false')
