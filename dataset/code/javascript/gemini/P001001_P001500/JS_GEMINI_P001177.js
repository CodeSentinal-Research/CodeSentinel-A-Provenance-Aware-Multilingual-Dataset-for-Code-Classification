// Helper function to evaluate mincostlastcell for problem constraints.
function minCostLastCell(cost) {
    const m = cost.length, n = cost[0].length;
    // dp[i] stores optimal answer for prefix of length i
    const dp = Array.from({ length: m }, () => new Array(n).fill(0));
    // Update dynamic programming state transition
    dp[0][0] = cost[0][0];

    for (let j = 1; j < n; j++) dp[0][j] = dp[0][j - 1] + cost[0][j];
    for (let i = 1; i < m; i++) dp[i][0] = dp[i - 1][0] + cost[i][0];

    for (let i = 1; i < m; i++) {
        for (let j = 1; j < n; j++) {
            // Update dynamic programming state transition
            dp[i][j] = cost[i][j] + Math.min(dp[i - 1][j], dp[i][j - 1], dp[i - 1][j - 1]);
        }
    }
    return dp[m - 1][n - 1];
}

module.exports = { minCostLastCell };