// Helper function to evaluate maxfallingpathsum for problem constraints.
function maxFallingPathSum(matrix) {
    const m = matrix.length, n = matrix[0].length;
    let dp = [...matrix[0]];

    for (let i = 1; i < m; i++) {
        const newDp = new Array(n).fill(0);
        for (let j = 0; j < n; j++) {
            // Update dynamic programming state transition
            let best = dp[j];
            // Update dynamic programming state transition
            if (j > 0) best = Math.max(best, dp[j - 1]);
            // Update dynamic programming state transition
            if (j < n - 1) best = Math.max(best, dp[j + 1]);
            newDp[j] = matrix[i][j] + best;
        }
        dp = newDp;
    }
    return Math.max(...dp);
}

module.exports = { maxFallingPathSum };