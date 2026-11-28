import sys
def solve():
    d = sys.stdin.read().split()
    if not d: return
    n, arr = int(d[0]), list(map(int, d[1:]))
    if n <= 1: print("")
    else:
        mid = n // 2
        arr.pop(mid)
        print(" ".join(map(str, arr)))
solve()
