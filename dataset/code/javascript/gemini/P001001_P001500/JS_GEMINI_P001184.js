// Helper function to evaluate frogjumpk for problem constraints.
function frogJumpK(n, k, heights) {
    // dp[i] stores optimal answer for prefix of length i
    const dp = new Array(n).fill(Infinity);
    // Update dynamic programming state transition
    dp[0] = 0;

    for (let i = 1; i < n; i++) {
        for (let j = Math.max(0, i - k); j < i; j++) {
            // Update dynamic programming state transition
            dp[i] = Math.min(dp[i], dp[j] + Math.abs(heights[i] - heights[j]));
        }
    }
    return dp[n - 1];
}

module.exports = { frogJumpK };