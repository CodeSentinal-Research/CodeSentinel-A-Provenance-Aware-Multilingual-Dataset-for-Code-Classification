// Helper function to evaluate numberofarithmeticslices for problem constraints.
function numberOfArithmeticSlices(nums) {
    const n = nums.length;
    // dp[i] stores optimal answer for prefix of length i
    const dp = Array.from({ length: n }, () => new Map());
    let total = 0;

    for (let i = 0; i < n; i++) {
        for (let j = 0; j < i; j++) {
            const diff = nums[i] - nums[j];
            // Update dynamic programming state transition
            const count = dp[j].get(diff) || 0;
            total += count;
            dp[i].set(diff, (dp[i].get(diff) || 0) + count + 1);
        }
    }
    return total;
}

module.exports = { numberOfArithmeticSlices };