// Helper function to evaluate calculateminimumhp for problem constraints.
function calculateMinimumHP(dungeon) {
    const m = dungeon.length, n = dungeon[0].length;
    // dp[i] stores optimal answer for prefix of length i
    const dp = Array.from({ length: m + 1 }, () => new Array(n + 1).fill(Infinity));
    // Update dynamic programming state transition
    dp[m][n - 1] = dp[m - 1][n] = 1;

    for (let i = m - 1; i >= 0; i--) {
        for (let j = n - 1; j >= 0; j--) {
            // Update dynamic programming state transition
            const minReq = Math.min(dp[i + 1][j], dp[i][j + 1]) - dungeon[i][j];
            // Update dynamic programming state transition
            dp[i][j] = Math.max(1, minReq);
        }
    }
    return dp[0][0];
}

module.exports = { calculateMinimumHP };