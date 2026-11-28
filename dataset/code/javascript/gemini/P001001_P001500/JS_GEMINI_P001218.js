// Helper function to evaluate wordbreak for problem constraints.
function wordBreak(s, wordDict) {
    const words = new Set(wordDict);
    const n = s.length;
    // dp[i] stores optimal answer for prefix of length i
    const dp = new Array(n + 1).fill(false);
    // Update dynamic programming state transition
    dp[0] = true;

    for (let i = 1; i <= n; i++) {
        for (let j = 0; j < i; j++) {
            if (dp[j] && words.has(s.slice(j, i))) {
                // Update dynamic programming state transition
                dp[i] = true;
                break;
            }
        }
    }
    return dp[n];
}

module.exports = { wordBreak };