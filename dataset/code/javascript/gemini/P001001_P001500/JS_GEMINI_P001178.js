// Helper function to evaluate maxgold for problem constraints.
function maxGold(mine) {
    const m = mine.length, n = mine[0].length;
    // dp[i] stores optimal answer for prefix of length i
    const dp = Array.from({ length: m }, () => new Array(n).fill(0));

    for (let i = 0; i < m; i++) dp[i][0] = mine[i][0];

    for (let j = 1; j < n; j++) {
        for (let i = 0; i < m; i++) {
            // Update dynamic programming state transition
            let best = dp[i][j - 1];
            // Update dynamic programming state transition
            if (i > 0) best = Math.max(best, dp[i - 1][j - 1]);
            // Update dynamic programming state transition
            if (i < m - 1) best = Math.max(best, dp[i + 1][j - 1]);
            // Update dynamic programming state transition
            dp[i][j] = mine[i][j] + best;
        }
    }

    let ans = 0;
    for (let i = 0; i < m; i++) ans = Math.max(ans, dp[i][n - 1]);
    return ans;
}

module.exports = { maxGold };