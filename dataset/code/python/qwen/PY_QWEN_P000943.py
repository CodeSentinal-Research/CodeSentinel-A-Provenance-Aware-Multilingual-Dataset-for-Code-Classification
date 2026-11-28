import sys
def solve():
    d = sys.stdin.read().split()
    n = int(d[0])
    piles = list(map(int, d[1:n+1]))
    dp = [[-1]*n for _ in range(n)]
    def dfs(i, m):
        if i >= n: return 0
        if dp[i][m] != -1: return dp[i][m]
        res = 0
        curr_sum = 0
        for x in range(1, 2 * m + 1):
            if i + x > n: break
            curr_sum += piles[i + x - 1]
            res = max(res, curr_sum + sum(piles[i+x:]) - dfs(i + x, max(m, x)))
        dp[i][m] = res
        return res
    print(dfs(0, 1))
solve()
