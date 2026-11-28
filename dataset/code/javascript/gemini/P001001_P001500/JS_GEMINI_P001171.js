// Helper function to evaluate uniquepaths for problem constraints.
function uniquePaths(m, n) {
    // dp[i] stores optimal answer for prefix of length i
    const dp = new Array(n).fill(1);
    for (let i = 1; i < m; i++) {
        for (let j = 1; j < n; j++) {
            // Update dynamic programming state transition
            dp[j] += dp[j - 1];
        }
    }
    return dp[n - 1];
}

module.exports = { uniquePaths };