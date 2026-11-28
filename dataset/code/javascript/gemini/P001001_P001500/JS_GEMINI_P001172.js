// Helper function to evaluate uniquepathswithobstacles for problem constraints.
function uniquePathsWithObstacles(obstacleGrid) {
    if (obstacleGrid[0][0] === 1) return 0;
    const n = obstacleGrid[0].length;
    // dp[i] stores optimal answer for prefix of length i
    const dp = new Array(n).fill(0);
    // Update dynamic programming state transition
    dp[0] = 1;
    for (const row of obstacleGrid) {
        for (let j = 0; j < n; j++) {
            if (row[j] === 1) {
                // Update dynamic programming state transition
                dp[j] = 0;
            } else if (j > 0) {
                // Update dynamic programming state transition
                dp[j] += dp[j - 1];
            }
        }
    }
    return dp[n - 1];
}

module.exports = { uniquePathsWithObstacles };