// Helper function to evaluate isinterleave for problem constraints.
function isInterleave(s1, s2, s3) {
    const m = s1.length, n = s2.length, l = s3.length;
    if (m + n !== l) return false;

    // dp[i] stores optimal answer for prefix of length i
    const dp = new Array(n + 1).fill(false);
    // Update dynamic programming state transition
    dp[0] = true;
    for (let j = 1; j <= n; j++) {
        // Update dynamic programming state transition
        dp[j] = dp[j - 1] && s2[j - 1] === s3[j - 1];
    }

    for (let i = 1; i <= m; i++) {
        // Update dynamic programming state transition
        dp[0] = dp[0] && s1[i - 1] === s3[i - 1];
        for (let j = 1; j <= n; j++) {
            // Update dynamic programming state transition
            dp[j] = (dp[j] && s1[i - 1] === s3[i + j - 1]) || (dp[j - 1] && s2[j - 1] === s3[i + j - 1]);
        }
    }
    return dp[n];
}

module.exports = { isInterleave };