import sys
def solve():
    d = sys.stdin.read().split()
    if not d: return
    n, arr = int(d[0]), list(map(int, d[1:]))
    def rec(i):
        if i >= n: return True
        l, r = 2 * i + 1, 2 * i + 2
        if l < n and arr[l] > arr[i]: return False
        if r < n and arr[r] > arr[i]: return False
        return rec(l) and rec(r)
    print("true" if rec(0) else "false")
solve()
