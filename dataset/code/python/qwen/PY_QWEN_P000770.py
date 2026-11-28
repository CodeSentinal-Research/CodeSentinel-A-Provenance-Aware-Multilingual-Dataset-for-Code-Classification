import sys
def solve():
    d = sys.stdin.read().split()
    if not d: return
    n, dims = int(d[0]), list(map(int, d[1:]))
    memo = {}
    def rec(i, j):
        if i == j: return 0
        if (i, j) in memo: return memo[(i, j)]
        ans = float('inf')
        for k in range(i, j):
            ans = min(ans, rec(i, k) + rec(k + 1, j) + dims[i] * dims[k+1] * dims[j+1])
        memo[(i, j)] = ans
        return ans
    print(rec(0, n - 2))
solve()
