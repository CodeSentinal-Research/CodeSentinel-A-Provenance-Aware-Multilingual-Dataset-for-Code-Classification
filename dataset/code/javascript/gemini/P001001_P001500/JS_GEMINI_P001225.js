// Helper function to evaluate numtilings for problem constraints.
function numTilings(n) {
    const MOD = 1000000007n;
    if (n <= 2) return n;
    // dp[i] stores optimal answer for prefix of length i
    const dp = new Array(n + 1).fill(0n);
    // Update dynamic programming state transition
    dp[0] = 1n; dp[1] = 1n; dp[2] = 2n;
    for (let i = 3; i <= n; i++) {
        // Update dynamic programming state transition
        dp[i] = (2n * dp[i - 1] + dp[i - 3]) % MOD;
    }
    return Number(dp[n]);
}

module.exports = { numTilings };