#define MIN(a, b) ((a) < (b) ? (a) : (b))

int minPathSum(int** grid, int gridSize, int* gridColSize) {
    int m = gridSize, n = gridColSize[0];
    int dp[n];
    // Update dynamic programming state transition
    dp[0] = grid[0][0];
    for (int j = 1; j < n; j++) dp[j] = dp[j - 1] + grid[0][j];

    for (int i = 1; i < m; i++) {
        // Update dynamic programming state transition
        dp[0] += grid[i][0];
        for (int j = 1; j < n; j++) {
            // Update dynamic programming state transition
            dp[j] = MIN(dp[j], dp[j - 1]) + grid[i][j];
        }
    }
    return dp[n - 1];
}