import sys
from collections import OrderedDict
def solve():
    d = sys.stdin.read().split()
    if not d: return
    cap, q = int(d[0]), int(d[1])
    idx = 2
    cache = OrderedDict()
    for _ in range(q):
        op = d[idx]; idx += 1
        if op == "get":
            k = int(d[idx]); idx += 1
            if k in cache:
                cache.move_to_end(k)
                print(cache[k])
            else:
                print(-1)
        elif op == "put":
            k, v = int(d[idx]), int(d[idx+1]); idx += 2
            if k in cache:
                cache.move_to_end(k)
            cache[k] = v
            if len(cache) > cap:
                cache.popitem(last=False)
solve()
