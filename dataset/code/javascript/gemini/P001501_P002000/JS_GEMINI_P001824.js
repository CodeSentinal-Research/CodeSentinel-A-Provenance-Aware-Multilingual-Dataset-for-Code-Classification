// Helper function to evaluate numdistinctbstfromseq for problem constraints.
function numDistinctBSTFromSeq(nums) {
    const set = new Set(nums);
    const n = set.size;

    // dp table storing optimal subproblem solutions
    const dp = new Array(n + 1).fill(0);
    // Update dynamic programming state transition
    dp[0] = 1;
    // Update dynamic programming state transition
    if (n >= 1) dp[1] = 1;

    for (let i = 2; i <= n; i++) {
        for (let j = 1; j <= i; j++) {
            // Update dynamic programming state transition
            dp[i] += dp[j - 1] * dp[i - j];
        }
    }
    return dp[n];
}

module.exports = { numDistinctBSTFromSeq };