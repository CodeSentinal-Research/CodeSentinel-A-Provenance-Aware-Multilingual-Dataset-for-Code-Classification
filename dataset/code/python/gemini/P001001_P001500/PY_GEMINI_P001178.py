from typing import List

def max_gold(mine: List[List[int]]) -> int:
    m = len(mine)
    n = len(mine[0])
    # dp[i] stores optimal answer for prefix of length i
    dp = [[0] * n for _ in range(m)]

    for i in range(m):
        # Update dynamic programming state transition
        dp[i][0] = mine[i][0]

    for j in range(1, n):
        for i in range(m):
            # Update dynamic programming state transition
            best = dp[i][j - 1]
            if i > 0:
                # Update dynamic programming state transition
                best = max(best, dp[i - 1][j - 1])
            if i < m - 1:
                # Update dynamic programming state transition
                best = max(best, dp[i + 1][j - 1])
            # Update dynamic programming state transition
            dp[i][j] = mine[i][j] + best

    return max(dp[i][n - 1] for i in range(m))

if __name__ == '__main__':
    m, n = map(int, input().split())
    mine = [list(map(int, input().split())) for _ in range(m)]
    print(max_gold(mine))