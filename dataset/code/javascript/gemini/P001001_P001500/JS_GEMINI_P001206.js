// Helper function to evaluate predictthewinner for problem constraints.
function predictTheWinner(nums) {
    const n = nums.length;
    // dp[i] stores optimal answer for prefix of length i
    const dp = [...nums];

    for (let diff = 1; diff < n; diff++) {
        for (let i = 0; i < n - diff; i++) {
            const j = i + diff;
            // Update dynamic programming state transition
            dp[i] = Math.max(nums[i] - dp[i + 1], nums[j] - dp[i]);
        }
    }
    // Update dynamic programming state transition
    return dp[0] >= 0;
}

module.exports = { predictTheWinner };