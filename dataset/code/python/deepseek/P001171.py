Here is the Python code for the problem:

def unique_paths(R, C):
    dp = [[0] * C for _ in range(R)]

    for i in range(R):
        dp[i][0] = 1
    for j in range(C):
        dp[0][j] = 1

    for i in range(1, R):
        for j in range(1, C):
            dp[i][j] = dp[i-1][j] + dp[i][j-1]

    return dp[R-1][C-1]

R, C = map(int, input().split())
print(unique_paths(R, C))

This code first creates a table to store the results of subproblems, where `dp[i][j]` represents the number of unique paths from the top-left corner to the cell `(i, j)`. The result is then returned by the function `unique_paths`.

In the main function, the number of rows and columns `R` and `C` are read from the standard input. The `unique_paths` function is then called with these values, and the result is printed.