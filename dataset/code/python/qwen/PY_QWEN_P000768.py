import sys
def solve():
    N = int(sys.stdin.read().split()[0])
    memo = {}
    def rec(n):
        if n <= 1: return 1
        if n in memo: return memo[n]
        ans = 0
        for i in range(1, n + 1): ans += rec(i - 1) * rec(n - i)
        memo[n] = ans
        return ans
    print(rec(N))
solve()
