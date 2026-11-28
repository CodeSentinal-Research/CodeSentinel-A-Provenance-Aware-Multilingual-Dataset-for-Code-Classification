Here is the Python code for the problem:

def tiling(n):
    dp = [[0 for _ in range(n+1)] for _ in range(2)]

    dp[0][0] = dp[0][1] = 1

    for i in range(2, n+1):
        dp[i%2][i] = dp[(i-1)%2][i-1] + dp[(i-1)%2][i]
        dp[i%2][i-1] = dp[(i-1)%2][i-1] + dp[(i-1)%2][i]

    return dp[n%2][n]

n = int(input())
print(tiling(n))

In this solution, we use a 2D dynamic programming (DP) approach to solve the problem. The DP array dp is initialized with all elements set to 0. For each cell (i, j), we have two options: either we can fill it with a domino or a tromino. Depending on the previous cell, we either fill the current cell with a domino (dp[i%2][j] = dp[(i-1)%2][j-1] + dp[(i-1)%2][j]) or a tromino (dp[i%2][j-1] = dp[(i-1)%2][j-1] + dp[(i-1)%2][j]). The total number of ways to fill the n-th cell is the sum of the ways to fill the (n-1)th cell (dp[n%2][n]), the (n-2)th cell (dp[(n-1)%2][n]) and the (n-1)th cell (dp[(n-2)%2][n]).