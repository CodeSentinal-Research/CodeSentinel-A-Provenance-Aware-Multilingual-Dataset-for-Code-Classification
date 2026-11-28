
s,t=input().strip(),input().strip()
from functools import lru_cache
@lru_cache(None)
def dp(i,j):
    if j==len(t): return True
    if i==len(s): return False
    if s[i].upper()==t[j]: return dp(i+1,j+1) or (s[i].islower() and dp(i+1,j))
    return s[i].islower() and dp(i+1,j)
print('YES' if dp(0,0) else 'NO')
