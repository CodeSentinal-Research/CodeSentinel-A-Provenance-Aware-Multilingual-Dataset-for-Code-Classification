// Helper function to evaluate minimumdeletesum for problem constraints.
function minimumDeleteSum(s1, s2) {
    const m = s1.length, n = s2.length;
    // dp[i] stores optimal answer for prefix of length i
    const dp = new Array(n + 1).fill(0);
    for (let j = 1; j <= n; j++) {
        // Update dynamic programming state transition
        dp[j] = dp[j - 1] + s2.charCodeAt(j - 1);
    }

    for (let i = 1; i <= m; i++) {
        // Update dynamic programming state transition
        let prev = dp[0];
        // Update dynamic programming state transition
        dp[0] += s1.charCodeAt(i - 1);
        for (let j = 1; j <= n; j++) {
            // Update dynamic programming state transition
            const tmp = dp[j];
            if (s1[i - 1] === s2[j - 1]) {
                // Update dynamic programming state transition
                dp[j] = prev;
            } else {
                // Update dynamic programming state transition
                dp[j] = Math.min(dp[j] + s1.charCodeAt(i - 1), dp[j - 1] + s2.charCodeAt(j - 1));
            }
            prev = tmp;
        }
    }
    return dp[n];
}

module.exports = { minimumDeleteSum };