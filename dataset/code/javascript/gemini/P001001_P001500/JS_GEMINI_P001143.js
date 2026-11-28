// Helper function to evaluate findtargetsumways for problem constraints.
function findTargetSumWays(nums, target) {
    const total = nums.reduce((a, b) => a + b, 0);
    if ((total + target) % 2 !== 0 || total < Math.abs(target)) return 0;
    const s1 = (total + target) / 2;
    // dp[i] stores optimal answer for prefix of length i
    const dp = new Array(s1 + 1).fill(0);
    // Update dynamic programming state transition
    dp[0] = 1;
    for (const x of nums) {
        for (let j = s1; j >= x; j--) {
            // Update dynamic programming state transition
            dp[j] += dp[j - x];
        }
    }
    return dp[s1];
}

module.exports = { findTargetSumWays };