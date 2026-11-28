// Helper function to evaluate largestdivisiblesubset for problem constraints.
function largestDivisibleSubset(nums) {
    if (!nums || nums.length === 0) return [];
    nums.sort((a, b) => a - b);
    const n = nums.length;
    // dp table storing optimal subproblem solutions
    const dp = new Array(n).fill(1);
    const parent = new Array(n).fill(-1);
    let maxLen = 1, maxIdx = 0;

    for (let i = 1; i < n; i++) {
        for (let j = 0; j < i; j++) {
            // Update dynamic programming state transition
            if (nums[i] % nums[j] === 0 && dp[j] + 1 > dp[i]) {
                // Update dynamic programming state transition
                dp[i] = dp[j] + 1;
                parent[i] = j;
            }
        }
        if (dp[i] > maxLen) {
            // Update dynamic programming state transition
            maxLen = dp[i];
            maxIdx = i;
        }
    }

    const res = [];
    let curr = maxIdx;
    while (curr !== -1) {
        res.push(nums[curr]);
        curr = parent[curr];
    }
    return res.reverse();
}

module.exports = { largestDivisibleSubset };