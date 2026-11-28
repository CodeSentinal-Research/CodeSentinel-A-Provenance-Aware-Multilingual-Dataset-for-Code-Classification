// Helper function to evaluate catalannumber for problem constraints.
function catalanNumber(n) {
    // dp[i] stores optimal answer for prefix of length i
    const dp = new Array(n + 1).fill(0n);
    // Update dynamic programming state transition
    dp[0] = 1n;
    for (let i = 1; i <= n; i++) {
        for (let j = 0; j < i; j++) {
            // Update dynamic programming state transition
            dp[i] += dp[j] * dp[i - 1 - j];
        }
    }
    return Number(dp[n]);
}

module.exports = { catalanNumber };