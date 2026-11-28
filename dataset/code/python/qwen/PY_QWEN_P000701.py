import sys
def solve():
    d = sys.stdin.read().split()
    if not d: return
    n, arr = int(d[0]), list(map(int, d[1:]))
    def rec(i):
        if i == n - 1: return arr[i]
        return min(arr[i], rec(i + 1))
    print(rec(0))
solve()
