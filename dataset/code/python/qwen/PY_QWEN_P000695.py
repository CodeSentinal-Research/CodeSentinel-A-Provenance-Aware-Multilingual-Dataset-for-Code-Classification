import sys
import bisect
def solve():
    d = sys.stdin.read().split()
    if not d: return
    n, arr, t = int(d[0]), list(map(int, d[1:-1])), int(d[-1])
    idx = bisect.bisect_left(arr, t)
    print(idx if idx < n and arr[idx] == t else -1)
solve()
