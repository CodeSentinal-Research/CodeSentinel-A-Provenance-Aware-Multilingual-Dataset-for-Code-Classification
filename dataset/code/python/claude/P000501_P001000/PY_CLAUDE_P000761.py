
s,t=input().strip(),input().strip()
from functools import lru_cache
@lru_cache(None)
def dp(i,j):
    if j==len(t): return 1
    if i==len(s): return 0
    res=dp(i+1,j)
    if s[i]==t[j]: res+=dp(i+1,j+1)
    return res
print(dp(0,0))
