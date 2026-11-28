// Helper function to evaluate numdistinct for problem constraints.
function numDistinct(s, t) {
    const m = s.length, n = t.length;
    // dp[i] stores optimal answer for prefix of length i
    const dp = new Array(n + 1).fill(0n);
    // Update dynamic programming state transition
    dp[0] = 1n;
    for (let i = 1; i <= m; i++) {
        for (let j = n; j >= 1; j--) {
            if (s[i - 1] === t[j - 1]) {
                // Update dynamic programming state transition
                dp[j] += dp[j - 1];
            }
        }
    }
    return Number(dp[n]);
}

module.exports = { numDistinct };