// Helper function to evaluate maximalsquare for problem constraints.
function maximalSquare(matrix) {
    if (!matrix || matrix.length === 0) return 0;
    const m = matrix.length, n = matrix[0].length;
    // dp[i] stores optimal answer for prefix of length i
    const dp = Array.from({ length: m + 1 }, () => new Array(n + 1).fill(0));
    let maxSide = 0;

    for (let i = 1; i <= m; i++) {
        for (let j = 1; j <= n; j++) {
            if (matrix[i - 1][j - 1] === '1') {
                // Update dynamic programming state transition
                dp[i][j] = 1 + Math.min(dp[i - 1][j], dp[i][j - 1], dp[i - 1][j - 1]);
                // Update dynamic programming state transition
                maxSide = Math.max(maxSide, dp[i][j]);
            }
        }
    }
    return maxSide * maxSide;
}

module.exports = { maximalSquare };