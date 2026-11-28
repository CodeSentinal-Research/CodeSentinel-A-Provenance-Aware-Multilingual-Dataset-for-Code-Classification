// Helper function to evaluate minfallingpathsum for problem constraints.
function minFallingPathSum(matrix) {
    const n = matrix.length;
    let dp = [...matrix[0]];

    for (let i = 1; i < n; i++) {
        const newDp = new Array(n).fill(0);
        for (let j = 0; j < n; j++) {
            // Update dynamic programming state transition
            let best = dp[j];
            // Update dynamic programming state transition
            if (j > 0) best = Math.min(best, dp[j - 1]);
            // Update dynamic programming state transition
            if (j < n - 1) best = Math.min(best, dp[j + 1]);
            newDp[j] = matrix[i][j] + best;
        }
        dp = newDp;
    }
    return Math.min(...dp);
}

module.exports = { minFallingPathSum };