// Helper function to evaluate change for problem constraints.
function change(amount, coins) {
    // dp[i] stores optimal answer for prefix of length i
    const dp = new Array(amount + 1).fill(0);
    // Update dynamic programming state transition
    dp[0] = 1;
    for (const c of coins) {
        for (let i = c; i <= amount; i++) {
            // Update dynamic programming state transition
            dp[i] += dp[i - c];
        }
    }
    return dp[amount];
}

module.exports = { change };