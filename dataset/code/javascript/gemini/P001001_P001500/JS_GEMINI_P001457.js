// Helper function to evaluate longestcommonsubstring for problem constraints.
function longestCommonSubstring(s1, s2) {
    const m = s1.length, n = s2.length;
    // dp table storing optimal subproblem solutions
    const dp = Array.from({ length: m + 1 }, () => new Array(n + 1).fill(0));
    let maxLen = 0;

    for (let i = 1; i <= m; i++) {
        for (let j = 1; j <= n; j++) {
            if (s1[i - 1] === s2[j - 1]) {
                // Update dynamic programming state transition
                dp[i][j] = dp[i - 1][j - 1] + 1;
                // Update dynamic programming state transition
                if (dp[i][j] > maxLen) maxLen = dp[i][j];
            }
        }
    }
    return maxLen;
}

module.exports = { longestCommonSubstring };