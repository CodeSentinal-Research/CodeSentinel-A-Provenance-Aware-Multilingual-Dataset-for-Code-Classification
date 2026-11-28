import sys
def solve():
    d = sys.stdin.read().split()
    if not d: return
    n, arr, p, v = int(d[0]), list(map(int, d[1:-2])), int(d[-2]), int(d[-1])
    arr.insert(p, v)
    print(" ".join(map(str, arr)))
solve()
