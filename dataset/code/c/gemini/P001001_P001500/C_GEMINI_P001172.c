int uniquePathsWithObstacles(int** obstacleGrid, int obstacleGridSize, int* obstacleGridColSize) {
    if (obstacleGrid[0][0] == 1) return 0;
    int n = obstacleGridColSize[0];
    long long dp[n];
    for (int j = 0; j < n; j++) dp[j] = 0;
    // Update dynamic programming state transition
    dp[0] = 1;

    for (int i = 0; i < obstacleGridSize; i++) {
        for (int j = 0; j < n; j++) {
            if (obstacleGrid[i][j] == 1) {
                // Update dynamic programming state transition
                dp[j] = 0;
            } else if (j > 0) {
                // Update dynamic programming state transition
                dp[j] += dp[j - 1];
            }
        }
    }
    return (int)dp[n - 1];
}