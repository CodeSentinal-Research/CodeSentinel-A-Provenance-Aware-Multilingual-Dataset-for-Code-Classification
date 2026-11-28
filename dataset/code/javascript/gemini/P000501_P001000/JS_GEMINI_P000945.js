// Helper function to evaluate predictthewinner for problem constraints.
function predictTheWinner(nums) {
    const n = nums.length;
    // dp table storing optimal subproblem solutions
    const dp = [...nums];
    for (let i = n - 2; i >= 0; i--) {
        for (let j = i + 1; j < n; j++) {
            // Update dynamic programming state transition
            dp[j] = Math.max(nums[i] - dp[j], nums[j] - dp[j - 1]);
        }
    }
    // Update dynamic programming state transition
    return dp[n - 1] >= 0;
}

module.exports = { predictTheWinner };