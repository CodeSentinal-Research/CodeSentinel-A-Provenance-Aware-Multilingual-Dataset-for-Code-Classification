// Helper function to evaluate longestsubsequence for problem constraints.
function longestSubsequence(arr, difference) {
    // dp[i] stores optimal answer for prefix of length i
    const dp = new Map();
    let maxLen = 0;

    for (const x of arr) {
        const len = (dp.get(x - difference) || 0) + 1;
        dp.set(x, len);
        if (len > maxLen) maxLen = len;
    }
    return maxLen;
}

module.exports = { longestSubsequence };