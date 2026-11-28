import sys
from sortedcontainers import SortedDict
def solve():
    d = sys.stdin.read().split()
    if not d: return
    q = int(d[0])
    idx = 1
    sd = SortedDict()
    for _ in range(q):
        op = d[idx]; idx += 1
        if op == "put":
            k, v = d[idx], int(d[idx+1]); idx += 2
            sd[k] = v
        elif op == "get":
            k = d[idx]; idx += 1
            print(sd.get(k, -1))
        elif op == "remove":
            k = d[idx]; idx += 1
            if k in sd: del sd[k]
        elif op == "firstKey": print(sd.keys()[0] if sd else -1)
        elif op == "lastKey": print(sd.keys()[-1] if sd else -1)
solve()
