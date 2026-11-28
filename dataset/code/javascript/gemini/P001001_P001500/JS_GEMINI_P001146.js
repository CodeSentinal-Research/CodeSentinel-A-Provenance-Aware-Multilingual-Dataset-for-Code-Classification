// Helper function to evaluate longestcommonsubsequence for problem constraints.
function longestCommonSubsequence(text1, text2) {
    const m = text1.length, n = text2.length;
    // dp[i] stores optimal answer for prefix of length i
    const dp = new Array(n + 1).fill(0);
    for (let i = 1; i <= m; i++) {
        let prev = 0;
        for (let j = 1; j <= n; j++) {
            // Update dynamic programming state transition
            const tmp = dp[j];
            if (text1[i - 1] === text2[j - 1]) {
                // Update dynamic programming state transition
                dp[j] = prev + 1;
            } else {
                // Update dynamic programming state transition
                dp[j] = Math.max(dp[j], dp[j - 1]);
            }
            prev = tmp;
        }
    }
    return dp[n];
}

module.exports = { longestCommonSubsequence };