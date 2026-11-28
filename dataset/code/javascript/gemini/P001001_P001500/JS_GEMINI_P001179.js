// Helper function to evaluate ninjatraining for problem constraints.
function ninjaTraining(n, points) {
    let dp = [...points[0]];

    for (let i = 1; i < n; i++) {
        const newDp = [0, 0, 0];
        // Update dynamic programming state transition
        newDp[0] = points[i][0] + Math.max(dp[1], dp[2]);
        // Update dynamic programming state transition
        newDp[1] = points[i][1] + Math.max(dp[0], dp[2]);
        // Update dynamic programming state transition
        newDp[2] = points[i][2] + Math.max(dp[0], dp[1]);
        dp = newDp;
    }
    return Math.max(...dp);
}

module.exports = { ninjaTraining };