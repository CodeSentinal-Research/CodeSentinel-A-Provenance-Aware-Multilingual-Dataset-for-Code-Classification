import sys
def solve():
    d = sys.stdin.read().split()
    if not d: return
    E, F = int(d[0]), int(d[1])
    memo = {}
    def rec(e, f):
        if f == 0 or f == 1: return f
        if e == 1: return f
        if (e, f) in memo: return memo[(e, f)]
        ans = float('inf')
        for k in range(1, f + 1):
            ans = min(ans, 1 + max(rec(e - 1, k - 1), rec(e, f - k)))
        memo[(e, f)] = ans
        return ans
    print(rec(E, F))
solve()
