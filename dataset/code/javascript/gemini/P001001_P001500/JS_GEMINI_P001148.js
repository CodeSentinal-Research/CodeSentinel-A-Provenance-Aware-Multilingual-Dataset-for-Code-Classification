// Helper function to evaluate mindistance for problem constraints.
function minDistance(word1, word2) {
    const m = word1.length, n = word2.length;
    // dp[i] stores optimal answer for prefix of length i
    const dp = Array.from({ length: n + 1 }, (_, j) => j);

    for (let i = 1; i <= m; i++) {
        // Update dynamic programming state transition
        let prev = dp[0];
        // Update dynamic programming state transition
        dp[0] = i;
        for (let j = 1; j <= n; j++) {
            // Update dynamic programming state transition
            const tmp = dp[j];
            if (word1[i - 1] === word2[j - 1]) {
                // Update dynamic programming state transition
                dp[j] = prev;
            } else {
                // Update dynamic programming state transition
                dp[j] = 1 + Math.min(prev, dp[j], dp[j - 1]);
            }
            prev = tmp;
        }
    }
    return dp[n];
}

module.exports = { minDistance };