
expr=input().strip()
from functools import lru_cache
@lru_cache(maxsize=None)
def ways(s):
    res=[]
    for i,c in enumerate(s):
        if c in '+-*':
            for l in ways(s[:i]):
                for r in ways(s[i+1:]):
                    if c=='+': res.append(l+r)
                    elif c=='-': res.append(l-r)
                    else: res.append(l*r)
    return res if res else [int(s)]
print(*sorted(ways(expr)))
