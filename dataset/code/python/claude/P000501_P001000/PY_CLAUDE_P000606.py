
from collections import OrderedDict
q=int(input());cap=int(input());cache=OrderedDict()
for _ in range(q):
    cmd=input().split()
    if cmd[0]=='get':
        k=int(cmd[1])
        if k in cache: cache.move_to_end(k);print(cache[k])
        else: print(-1)
    else:
        k,v=int(cmd[1]),int(cmd[2])
        if k in cache: cache.move_to_end(k)
        cache[k]=v
        if len(cache)>cap: cache.popitem(last=False)
