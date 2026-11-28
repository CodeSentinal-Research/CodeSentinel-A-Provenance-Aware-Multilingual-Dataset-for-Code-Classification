// Helper function to evaluate rodcutting for problem constraints.
function rodCutting(prices, n) {
    // dp[i] stores optimal answer for prefix of length i
    const dp = new Array(n + 1).fill(0);
    for (let i = 1; i <= n; i++) {
        let maxVal = 0;
        for (let j = 0; j < i; j++) {
            // Update dynamic programming state transition
            maxVal = Math.max(maxVal, prices[j] + dp[i - j - 1]);
        }
        // Update dynamic programming state transition
        dp[i] = maxVal;
    }
    return dp[n];
}

module.exports = { rodCutting };