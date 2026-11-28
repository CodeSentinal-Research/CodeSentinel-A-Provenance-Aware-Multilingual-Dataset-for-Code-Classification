// Helper function to evaluate longestpalindromesubseq for problem constraints.
function longestPalindromeSubseq(s) {
    const n = s.length;
    // dp[i] stores optimal answer for prefix of length i
    const dp = Array.from({ length: n }, () => new Array(n).fill(0));

    for (let i = n - 1; i >= 0; i--) {
        // Update dynamic programming state transition
        dp[i][i] = 1;
        for (let j = i + 1; j < n; j++) {
            if (s[i] === s[j]) {
                // Update dynamic programming state transition
                dp[i][j] = dp[i + 1][j - 1] + 2;
            } else {
                // Update dynamic programming state transition
                dp[i][j] = Math.max(dp[i + 1][j], dp[i][j - 1]);
            }
        }
    }
    return dp[0][n - 1];
}

module.exports = { longestPalindromeSubseq };