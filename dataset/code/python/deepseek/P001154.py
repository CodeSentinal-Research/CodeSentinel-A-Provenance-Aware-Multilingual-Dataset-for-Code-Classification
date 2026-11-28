def matrix_chain():
    n = int(input())
    dimensions = list(map(int, input().split()))

    dp = [[0 for _ in range(n+1)] for _ in range(n+1)]
    for l in range(2, n+1):
        for i in range(1, n-l+2):
            j = i + l - 1
            dp[i][j] = float('inf')
            for k in range(i, j):
                q = dp[i][k] + dp[k+1][j] + dimensions[i-1] * dimensions[k] * dimensions[j]
                dp[i][j] = min(dp[i][j], q)

    print(dp[1][n])


if __name__ == "__main__":
    matrix_chain()
This Python code uses dynamic programming to solve the Matrix Chain Multiplication problem. The main part of the code is the innermost loop where the computation of the minimum number of scalar multiplications takes place. The inner loop iterates over all possible split points to compute the minimum number of multiplications. The final minimum number of multiplications is stored in the `dp[i][j]` matrix.