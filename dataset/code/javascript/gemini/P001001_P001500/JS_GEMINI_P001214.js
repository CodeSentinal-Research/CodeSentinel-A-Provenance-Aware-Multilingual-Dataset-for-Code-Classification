// Helper function to evaluate strangeprinter for problem constraints.
function strangePrinter(s) {
    if (!s) return 0;
    const n = s.length;
    // dp[i] stores optimal answer for prefix of length i
    const dp = Array.from({ length: n }, () => new Array(n).fill(0));

    for (let i = n - 1; i >= 0; i--) {
        // Update dynamic programming state transition
        dp[i][i] = 1;
        for (let j = i + 1; j < n; j++) {
            if (s[i] === s[j]) {
                // Update dynamic programming state transition
                dp[i][j] = dp[i][j - 1];
            } else {
                let minTurns = Infinity;
                for (let k = i; k < j; k++) {
                    // Update dynamic programming state transition
                    minTurns = Math.min(minTurns, dp[i][k] + dp[k + 1][j]);
                }
                // Update dynamic programming state transition
                dp[i][j] = minTurns;
            }
        }
    }
    return dp[0][n - 1];
}

module.exports = { strangePrinter };