// Helper function to evaluate coinchange for problem constraints.
function coinChange(coins, amount) {
    // dp[i] stores optimal answer for prefix of length i
    const dp = new Array(amount + 1).fill(amount + 1);
    // Update dynamic programming state transition
    dp[0] = 0;
    for (const c of coins) {
        for (let i = c; i <= amount; i++) {
            // Update dynamic programming state transition
            dp[i] = Math.min(dp[i], dp[i - c] + 1);
        }
    }
    return dp[amount] > amount ? -1 : dp[amount];
}

module.exports = { coinChange };