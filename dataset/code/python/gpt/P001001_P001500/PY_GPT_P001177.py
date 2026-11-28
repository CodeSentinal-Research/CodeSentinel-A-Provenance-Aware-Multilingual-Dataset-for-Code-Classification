# problem title : Minimum Cost to Reach Last Cell
# Solve the stated task using standard input and standard output.
from typing import List

def min_cost_last_cell(cost: List[List[int]]) -> int:
    m = len(cost)
    n = len(cost[0])
    dp = [[0] * n for _ in range(m)]
    dp[0][0] = cost[0][0]

    for j in range(1, n):
        dp[0][j] = dp[0][j - 1] + cost[0][j]
    for i in range(1, m):
        dp[i][0] = dp[i - 1][0] + cost[i][0]

    for i in range(1, m):
        for j in range(1, n):
            dp[i][j] = cost[i][j] + min(dp[i - 1][j], dp[i][j - 1], dp[i - 1][j - 1])

    return dp[m - 1][n - 1]

if __name__ == '__main__':
    m, n = map(int, input().split())
    cost = [list(map(int, input().split())) for _ in range(m)]
    print(min_cost_last_cell(cost))
