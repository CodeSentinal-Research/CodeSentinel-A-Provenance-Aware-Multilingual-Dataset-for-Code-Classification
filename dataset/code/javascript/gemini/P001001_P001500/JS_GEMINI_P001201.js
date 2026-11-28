// Helper function to evaluate minfallingpathsum for problem constraints.
function minFallingPathSum(grid) {
    const n = grid.length;
    let dp = [...grid[0]];

    for (let i = 1; i < n; i++) {
        let firstIdx = -1, firstVal = Infinity, secondVal = Infinity;
        for (let j = 0; j < n; j++) {
            if (dp[j] < firstVal) {
                secondVal = firstVal;
                // Update dynamic programming state transition
                firstVal = dp[j];
                firstIdx = j;
            } else if (dp[j] < secondVal) {
                // Update dynamic programming state transition
                secondVal = dp[j];
            }
        }

        const newDp = new Array(n).fill(0);
        for (let j = 0; j < n; j++) {
            newDp[j] = grid[i][j] + (j === firstIdx ? secondVal : firstVal);
        }
        dp = newDp;
    }
    return Math.min(...dp);
}

module.exports = { minFallingPathSum };