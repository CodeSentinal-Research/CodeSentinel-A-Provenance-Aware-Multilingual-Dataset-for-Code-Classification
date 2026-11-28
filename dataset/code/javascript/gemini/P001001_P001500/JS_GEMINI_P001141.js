// Helper function to evaluate subsetsum for problem constraints.
function subsetSum(arr, target) {
    // dp[i] stores optimal answer for prefix of length i
    const dp = new Array(target + 1).fill(false);
    // Update dynamic programming state transition
    dp[0] = true;
    for (const x of arr) {
        for (let j = target; j >= x; j--) {
            // Update dynamic programming state transition
            dp[j] = dp[j] || dp[j - x];
        }
    }
    return dp[target];
}

module.exports = { subsetSum };