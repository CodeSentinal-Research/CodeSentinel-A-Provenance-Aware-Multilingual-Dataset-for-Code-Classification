// Helper function to evaluate supereggdrop for problem constraints.
function superEggDrop(k, n) {
    // dp[i] stores optimal answer for prefix of length i
    const dp = new Array(k + 1).fill(0);
    let m = 0;
    while (dp[k] < n) {
        m++;
        for (let i = k; i > 0; i--) {
            // Update dynamic programming state transition
            dp[i] = dp[i] + dp[i - 1] + 1;
        }
    }
    return m;
}

module.exports = { superEggDrop };