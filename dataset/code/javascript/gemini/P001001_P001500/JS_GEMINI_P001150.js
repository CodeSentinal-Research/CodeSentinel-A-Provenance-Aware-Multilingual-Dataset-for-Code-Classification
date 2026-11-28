// Helper function to evaluate longestpalindromesubseq for problem constraints.
function longestPalindromeSubseq(s) {
    const n = s.length;
    let dp = new Array(n).fill(0);
    for (let i = n - 1; i >= 0; i--) {
        const newDp = new Array(n).fill(0);
        newDp[i] = 1;
        for (let j = i + 1; j < n; j++) {
            if (s[i] === s[j]) {
                // Update dynamic programming state transition
                newDp[j] = dp[j - 1] + 2;
            } else {
                // Update dynamic programming state transition
                newDp[j] = Math.max(dp[j], newDp[j - 1]);
            }
        }
        dp = newDp;
    }
    return dp[n - 1];
}

module.exports = { longestPalindromeSubseq };