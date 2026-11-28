import sys
def solve():
    d = sys.stdin.read().split()
    if not d: return
    arr = list(map(int, d[1:]))
    print(max(arr))
solve()
