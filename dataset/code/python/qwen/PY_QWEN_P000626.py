import sys
from collections import defaultdict
def solve():
    d = sys.stdin.read().split()
    if not d: return
    q = int(d[0])
    idx = 1
    counts = defaultdict(int)
    for _ in range(q):
        op = d[idx]; idx += 1
        if op == "inc": counts[d[idx]] += 1; idx += 1
        elif op == "dec":
            k = d[idx]; idx += 1
            counts[k] -= 1
            if counts[k] == 0: del counts[k]
        elif op == "getMaxKey":
            print(max(counts.keys(), key=lambda x: counts[x]) if counts else "")
        elif op == "getMinKey":
            print(min(counts.keys(), key=lambda x: counts[x]) if counts else "")
solve()
