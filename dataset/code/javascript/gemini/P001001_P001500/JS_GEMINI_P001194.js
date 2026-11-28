// Helper function to evaluate maxsumafterpartitioning for problem constraints.
function maxSumAfterPartitioning(arr, k) {
    const n = arr.length;
    // dp[i] stores optimal answer for prefix of length i
    const dp = new Array(n + 1).fill(0);
    for (let i = 1; i <= n; i++) {
        let curMax = 0;
        for (let j = 1; j <= Math.min(k, i); j++) {
            curMax = Math.max(curMax, arr[i - j]);
            // Update dynamic programming state transition
            dp[i] = Math.max(dp[i], dp[i - j] + curMax * j);
        }
    }
    return dp[n];
}

module.exports = { maxSumAfterPartitioning };