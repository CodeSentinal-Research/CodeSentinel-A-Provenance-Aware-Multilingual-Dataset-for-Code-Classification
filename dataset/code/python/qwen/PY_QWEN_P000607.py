import sys
from collections import defaultdict, OrderedDict
def solve():
    d = sys.stdin.read().split()
    if not d: return
    cap, q = int(d[0]), int(d[1])
    idx = 2
    freq = defaultdict(OrderedDict)
    key_freq = {}
    min_f = 0
    for _ in range(q):
        op = d[idx]; idx += 1
        if op == "get":
            k = int(d[idx]); idx += 1
            if k not in key_freq: print(-1)
            else:
                f = key_freq[k]
                v = freq[f].pop(k)
                if not freq[f] and min_f == f: min_f += 1
                key_freq[k] = f + 1
                freq[f+1][k] = v
                print(v)
        elif op == "put":
            k, v = int(d[idx]), int(d[idx+1]); idx += 2
            if cap == 0: continue
            if k in key_freq:
                f = key_freq[k]
                freq[f].pop(k)
                if not freq[f] and min_f == f: min_f += 1
                key_freq[k] = f + 1
                freq[f+1][k] = v
            else:
                if len(key_freq) >= cap:
                    mk, _ = freq[min_f].popitem(last=False)
                    del key_freq[mk]
                key_freq[k] = 1
                freq[1][k] = v
                min_f = 1
solve()
