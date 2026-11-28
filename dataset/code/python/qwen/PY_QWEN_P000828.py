import sys
import bisect
def solve():
    d = sys.stdin.read().split()
    if not d: return
    n = int(d[0])
    intervals = []
    idx = 1
    for i in range(n):
        s, e = int(d[idx]), int(d[idx+1])
        intervals.append((s, e, i))
        idx += 2
    starts = sorted([(intervals[i][0], i) for i in range(n)])
    start_vals = [x[0] for x in starts]
    res = [-1] * n
    for s, e, orig_idx in intervals:
        idx = bisect.bisect_left(start_vals, e)
        if idx < n:
            res[orig_idx] = starts[idx][1]
    print(" ".join(map(str, res)))
solve()
