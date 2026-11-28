import sys
import bisect
def solve():
    d = sys.stdin.read().split()
    if not d: return
    n, arr, t = int(d[0]), list(map(int, d[1:-1])), int(d[-1])
    idx = bisect.bisect_right(arr, t) - 1
    print(idx if idx >= 0 and arr[idx] == t else -1)
solve()
