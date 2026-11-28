import sys
def solve():
    d = sys.stdin.read().split()
    if not d: return
    n, arr, m, k = int(d[0]), list(map(int, d[1:-2])), int(d[-2]), int(d[-1])
    res = []
    i = 0
    while i < n:
        res.extend(arr[i:i+m])
        i += m + k
    print(" ".join(map(str, res)))
solve()
