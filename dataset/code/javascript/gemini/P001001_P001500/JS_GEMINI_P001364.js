// Helper function to evaluate canpartitionksubsets for problem constraints.
function canPartitionKSubsets(nums, k) {
    const total = nums.reduce((a, b) => a + b, 0);
    if (total % k !== 0) return false;
    const target = total / k;
    nums.sort((a, b) => a - b);
    const n = nums.length;
    if (nums[n - 1] > target) return false;

    // dp table storing optimal subproblem solutions
    const dp = new Array(1 << n).fill(-1);
    // Update dynamic programming state transition
    dp[0] = 0;

    for (let mask = 0; mask < (1 << n); mask++) {
        // Update dynamic programming state transition
        if (dp[mask] === -1) continue;
        for (let i = 0; i < n; i++) {
            if ((mask & (1 << i)) === 0) {
                // Update dynamic programming state transition
                if (dp[mask] + nums[i] <= target) {
                    // Update dynamic programming state transition
                    dp[mask | (1 << i)] = (dp[mask] + nums[i]) % target;
                }
            }
        }
    }
    // Update dynamic programming state transition
    return dp[(1 << n) - 1] === 0;
}

module.exports = { canPartitionKSubsets };