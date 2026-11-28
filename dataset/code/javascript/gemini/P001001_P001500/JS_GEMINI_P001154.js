// Helper function to evaluate matrixchainmultiplication for problem constraints.
function matrixChainMultiplication(arr) {
    const n = arr.length;
    // dp[i] stores optimal answer for prefix of length i
    const dp = Array.from({ length: n }, () => new Array(n).fill(0));

    for (let len = 2; len < n; len++) {
        for (let i = 1; i <= n - len; i++) {
            const j = i + len - 1;
            // Update dynamic programming state transition
            dp[i][j] = Infinity;
            for (let k = i; k < j; k++) {
                // Update dynamic programming state transition
                const q = dp[i][k] + dp[k + 1][j] + arr[i - 1] * arr[k] * arr[j];
                // Update dynamic programming state transition
                if (q < dp[i][j]) dp[i][j] = q;
            }
        }
    }
    return dp[1][n - 1];
}

module.exports = { matrixChainMultiplication };