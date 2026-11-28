
expr=input().strip()
from functools import lru_cache
@lru_cache(None)
def ways(e):
    res=[]
    for i,c in enumerate(e):
        if c in '+-*':
            for l in ways(e[:i]):
                for r in ways(e[i+1:]):
                    if c=='+': res.append(l+r)
                    elif c=='-': res.append(l-r)
                    else: res.append(l*r)
    if not res: res=[int(e)]
    return res
print(*sorted(ways(expr)))
