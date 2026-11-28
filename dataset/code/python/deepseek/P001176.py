Here's the Python code to solve the problem.

def maxFallingPathSum(matrix):
    n = len(matrix)

    dp = [[0]*n for _ in range(n)]

    for i in range(n):
        dp[i][i] = matrix[i][i]

    for i in range(n-1, -1, -1):
        for j in range(n):
            if i+1 < n:
                dp[i][j] = max(dp[i][j], dp[i+1][j] + matrix[i][j])
            if j+1 < n:
                dp[i][j] = max(dp[i][j], dp[i][j+1] + matrix[i][j])
            if i+1 < n and j+1 < n:
                dp[i][j] = max(dp[i][j], dp[i+1][j+1] + matrix[i][j])

    return max(dp[i][j] for i in range(n) for j in range(n))

n = int(input())
matrix = [[int(x) for x in input().split()] for _ in range(n)]
print(maxFallingPathSum(matrix))

This code works by first initializing a 2D DP array with the same dimensions as the input matrix. Then, for each cell in the matrix, we update the DP array by considering three possibilities: the cell is part of a falling path, the cell above is part of a falling path, and the cell above-left and below-right are part of a falling path. The maximum of these three possibilities is used to update the DP array. Finally, the maximum value in the DP array is returned as the maximum possible sum of the falling path.