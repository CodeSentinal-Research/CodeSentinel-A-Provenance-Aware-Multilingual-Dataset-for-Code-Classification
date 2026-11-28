import sys
def solve():
    d = sys.stdin.read().split()
    if not d: return
    n, arr, x = int(d[0]), list(map(int, d[1:-1])), int(d[-1])
    print(" ".join(map(str, [v for v in arr if v < x] + [v for v in arr if v >= x])))
solve()
