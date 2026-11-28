// Helper function to evaluate maxresult for problem constraints.
function maxResult(nums, k) {
    const n = nums.length;
    // dp table storing optimal subproblem solutions
    const dp = new Array(n).fill(0);
    // Update dynamic programming state transition
    dp[0] = nums[0];
    const q = [0];

    for (let i = 1; i < n; i++) {
        while (q.length > 0 && q[0] < i - k) {
            q.shift();
        }
        // Update dynamic programming state transition
        dp[i] = dp[q[0]] + nums[i];
        // Update dynamic programming state transition
        while (q.length > 0 && dp[q[q.length - 1]] <= dp[i]) {
            q.pop();
        }
        q.push(i);
    }
    return dp[n - 1];
}

module.exports = { maxResult };