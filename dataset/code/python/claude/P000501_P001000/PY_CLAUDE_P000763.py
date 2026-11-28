
s,p=input().strip(),input().strip()
from functools import lru_cache
@lru_cache(None)
def dp(i,j):
    if j==len(p): return i==len(s)
    first=i<len(s) and (p[j]=='.' or p[j]==s[i])
    if j+1<len(p) and p[j+1]=='*':
        return dp(i,j+2) or (first and dp(i+1,j))
    return first and dp(i+1,j+1)
print('true' if dp(0,0) else 'false')
