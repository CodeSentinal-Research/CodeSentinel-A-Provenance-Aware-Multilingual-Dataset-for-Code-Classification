import sys
def solve():
    d = sys.stdin.read().split()
    if not d: return
    n, arr = int(d[0]), list(map(int, d[1:]))
    def rec(l, r):
        if l >= r: return True
        if arr[l] != arr[r]: return False
        return rec(l + 1, r - 1)
    print("true" if rec(0, n - 1) else "false")
solve()
