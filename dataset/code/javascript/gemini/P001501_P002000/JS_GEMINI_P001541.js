// Helper function to evaluate maxsumkconsecutive for problem constraints.
function maxSumKConsecutive(nums, k) {
    if (nums.length < k) return 0;
    let curSum = 0;
    for (let i = 0; i < k; i++) curSum += nums[i];
    let maxSum = curSum;

    for (let i = k; i < nums.length; i++) {
        curSum += nums[i] - nums[i - k];
        if (curSum > maxSum) maxSum = curSum;
    }
    return maxSum;
}

module.exports = { maxSumKConsecutive };