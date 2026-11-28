// Helper function to evaluate countpalindromicsubsequences for problem constraints.
function countPalindromicSubsequences(s) {
    const MOD = 1000000007n;
    const n = s.length;
    // dp[i] stores optimal answer for prefix of length i
    const dp = Array.from({ length: n }, () => new Array(n).fill(0n));

    for (let i = 0; i < n; i++) dp[i][i] = 1n;

    for (let len = 2; len <= n; len++) {
        for (let i = 0; i <= n - len; i++) {
            const j = i + len - 1;
            if (s[i] === s[j]) {
                // Update dynamic programming state transition
                dp[i][j] = (dp[i + 1][j] + dp[i][j - 1] + 1n) % MOD;
            } else {
                // Update dynamic programming state transition
                dp[i][j] = (dp[i + 1][j] + dp[i][j - 1] - dp[i + 1][j - 1] + MOD) % MOD;
            }
        }
    }
    return Number(dp[0][n - 1]);
}

module.exports = { countPalindromicSubsequences };