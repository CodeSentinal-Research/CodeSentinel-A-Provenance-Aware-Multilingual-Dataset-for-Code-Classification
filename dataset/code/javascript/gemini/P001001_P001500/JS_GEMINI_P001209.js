// Helper function to evaluate stonegameiii for problem constraints.
function stoneGameIII(stoneValue) {
    const n = stoneValue.length;
    // dp[i] stores optimal answer for prefix of length i
    const dp = new Array(n + 3).fill(0);

    for (let i = n - 1; i >= 0; i--) {
        let take = 0;
        // Update dynamic programming state transition
        dp[i] = -Infinity;
        for (let k = 1; k <= 3; k++) {
            if (i + k <= n) {
                take += stoneValue[i + k - 1];
                // Update dynamic programming state transition
                dp[i] = Math.max(dp[i], take - dp[i + k]);
            }
        }
    }
    if (dp[0] > 0) return "Alice";
    if (dp[0] < 0) return "Bob";
    return "Tie";
}

module.exports = { stoneGameIII };