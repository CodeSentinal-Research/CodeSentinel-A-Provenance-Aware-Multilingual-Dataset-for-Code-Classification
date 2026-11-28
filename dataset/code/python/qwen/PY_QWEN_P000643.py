import sys
def solve():
    d = sys.stdin.read().split()
    if not d: return
    n, arr, v = int(d[0]), list(map(int, d[1:-1])), int(d[-1])
    if v in arr: arr.remove(v)
    print(" ".join(map(str, arr)))
solve()
