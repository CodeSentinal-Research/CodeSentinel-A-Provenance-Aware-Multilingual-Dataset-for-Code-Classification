import sys
def solve():
    d = sys.stdin.read().split()
    if not d: return
    arr = list(map(int, d[1:]))
    if arr: print(" ".join(map(str, [arr[-1]] + arr[:-1])))
solve()
