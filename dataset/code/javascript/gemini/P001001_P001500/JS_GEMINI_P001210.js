// Helper function to evaluate optimalstrategy for problem constraints.
function optimalStrategy(arr) {
    const n = arr.length;
    // dp[i] stores optimal answer for prefix of length i
    const dp = Array.from({ length: n }, () => new Array(n).fill(0));

    for (let len = 1; len <= n; len++) {
        for (let i = 0; i <= n - len; i++) {
            const j = i + len - 1;
            // Update dynamic programming state transition
            const x = (i + 2 <= j) ? dp[i + 2][j] : 0;
            // Update dynamic programming state transition
            const y = (i + 1 <= j - 1) ? dp[i + 1][j - 1] : 0;
            // Update dynamic programming state transition
            const z = (i <= j - 2) ? dp[i][j - 2] : 0;
            // Update dynamic programming state transition
            dp[i][j] = Math.max(arr[i] + Math.min(x, y), arr[j] + Math.min(y, z));
        }
    }
    return dp[0][n - 1];
}

module.exports = { optimalStrategy };