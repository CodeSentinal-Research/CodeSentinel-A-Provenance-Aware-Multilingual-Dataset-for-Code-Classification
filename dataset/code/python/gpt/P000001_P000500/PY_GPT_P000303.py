# problem title : Word Break II
# Memoized DFS returns every sentence that can be formed from a valid dictionary prefix.
from functools import lru_cache
s=input(); words=set(input().split())
@lru_cache(None)
def f(i):
    if i==len(s): return ['']
    out=[]
    for j in range(i+1,len(s)+1):
        w=s[i:j]
        if w in words:
            for tail in f(j): out.append(w+(" "+tail if tail else ""))
    return out
print(*f(0),sep='\n')
