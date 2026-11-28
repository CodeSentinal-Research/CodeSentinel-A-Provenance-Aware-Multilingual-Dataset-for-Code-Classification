// Helper function to evaluate minimumtotal for problem constraints.
function minimumTotal(triangle) {
    const n = triangle.length;
    // dp[i] stores optimal answer for prefix of length i
    const dp = [...triangle[n - 1]];

    for (let i = n - 2; i >= 0; i--) {
        for (let j = 0; j <= i; j++) {
            // Update dynamic programming state transition
            dp[j] = triangle[i][j] + Math.min(dp[j], dp[j + 1]);
        }
    }
    return dp[0];
}

module.exports = { minimumTotal };