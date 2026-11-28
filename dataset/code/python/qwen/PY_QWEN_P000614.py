import sys
def solve():
    d = sys.stdin.read().split()
    if not d: return
    n, arr, k = int(d[0]), list(map(int, d[1:-1])), int(d[-1])
    arr[k-1], arr[n-k] = arr[n-k], arr[k-1]
    print(" ".join(map(str, arr)))
solve()
