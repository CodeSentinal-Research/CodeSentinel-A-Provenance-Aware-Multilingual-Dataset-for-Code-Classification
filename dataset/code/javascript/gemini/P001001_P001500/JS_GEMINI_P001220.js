// Helper function to evaluate numtrees for problem constraints.
function numTrees(n) {
    // dp[i] stores optimal answer for prefix of length i
    const dp = new Array(n + 1).fill(0);
    // Update dynamic programming state transition
    dp[0] = 1;
    for (let i = 1; i <= n; i++) {
        for (let j = 0; j < i; j++) {
            // Update dynamic programming state transition
            dp[i] += dp[j] * dp[i - 1 - j];
        }
    }
    return dp[n];
}

module.exports = { numTrees };