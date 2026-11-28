
s,p=input().strip(),input().strip()
from functools import lru_cache
@lru_cache(None)
def dp(i,j):
    if i==len(s) and j==len(p): return True
    if j==len(p): return False
    if p[j]=='*': return dp(i,j+1) or (i<len(s) and dp(i+1,j))
    if i<len(s) and (p[j]=='?' or p[j]==s[i]): return dp(i+1,j+1)
    return False
print('true' if dp(0,0) else 'false')
