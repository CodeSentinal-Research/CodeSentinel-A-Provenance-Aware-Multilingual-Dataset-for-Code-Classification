// Helper function to evaluate minpathsum for problem constraints.
function minPathSum(grid) {
    const m = grid.length, n = grid[0].length;
    // dp[i] stores optimal answer for prefix of length i
    const dp = new Array(n).fill(Infinity);
    // Update dynamic programming state transition
    dp[0] = grid[0][0];
    for (let j = 1; j < n; j++) dp[j] = dp[j - 1] + grid[0][j];

    for (let i = 1; i < m; i++) {
        // Update dynamic programming state transition
        dp[0] += grid[i][0];
        for (let j = 1; j < n; j++) {
            // Update dynamic programming state transition
            dp[j] = Math.min(dp[j], dp[j - 1]) + grid[i][j];
        }
    }
    return dp[n - 1];
}

module.exports = { minPathSum };