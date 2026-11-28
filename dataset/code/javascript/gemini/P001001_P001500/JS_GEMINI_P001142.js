// Helper function to evaluate canpartition for problem constraints.
function canPartition(nums) {
    const total = nums.reduce((a, b) => a + b, 0);
    if (total % 2 !== 0) return false;
    const target = total / 2;
    // dp[i] stores optimal answer for prefix of length i
    const dp = new Array(target + 1).fill(false);
    // Update dynamic programming state transition
    dp[0] = true;
    for (const x of nums) {
        for (let j = target; j >= x; j--) {
            // Update dynamic programming state transition
            dp[j] = dp[j] || dp[j - x];
        }
    }
    return dp[target];
}

module.exports = { canPartition };