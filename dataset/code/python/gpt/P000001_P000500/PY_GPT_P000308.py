# problem title : Different Ways to Add Parentheses
# Divide the expression at every operator and combine all results from both sides.
from functools import lru_cache
s=input().replace(' ','')
@lru_cache(None)
def f(x):
    if x.isdigit(): return [int(x)]
    out=[]
    for i,ch in enumerate(x):
        if ch in '+-*':
            for a in f(x[:i]):
                for b in f(x[i+1:]): out.append(a+b if ch=='+' else a-b if ch=='-' else a*b)
    return out
print(*f(s))
