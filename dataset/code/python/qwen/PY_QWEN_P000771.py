import sys
def solve():
    d = sys.stdin.read().split()
    if not d: return
    n = int(d[0])
    keys = list(map(int, d[1:n+1]))
    freq = list(map(int, d[n+1:2*n+1]))
    memo = {}
    def rec(i, j, lvl):
        if i > j: return 0
        if (i, j) in memo: return memo[(i, j)]
        ans = float('inf')
        for k in range(i, j + 1):
            ans = min(ans, rec(i, k - 1, lvl + 1) + rec(k + 1, j, lvl + 1) + lvl * freq[k])
        memo[(i, j)] = ans
        return ans
    print(rec(0, n - 1, 1))
solve()
