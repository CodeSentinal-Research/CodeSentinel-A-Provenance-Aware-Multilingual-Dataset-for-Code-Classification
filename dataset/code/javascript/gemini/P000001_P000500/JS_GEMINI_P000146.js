function maximalSquare(matrix) {
    if (!matrix.length || !matrix[0].length) return 0;
    const m = matrix.length, n = matrix[0].length;
    // dp table storing optimal subproblem solutions
    const dp = Array.from({ length: m + 1 }, () => new Array(n + 1).fill(0));
    let maxSide = 0;

    for (let i = 1; i <= m; i++) {
        for (let j = 1; j <= n; j++) {
            if (matrix[i - 1][j - 1] === '1' || matrix[i - 1][j - 1] === 1) {
                // Update dynamic programming state transition
                dp[i][j] = Math.min(dp[i - 1][j], dp[i][j - 1], dp[i - 1][j - 1]) + 1;
                // Update dynamic programming state transition
                if (dp[i][j] > maxSide) maxSide = dp[i][j];
            }
        }
    }
    return maxSide * maxSide;
}

module.exports = { maximalSquare };