// Helper function to evaluate earliestprefixsum for problem constraints.
function earliestPrefixSum(nums, x) {
    let curSum = 0;
    for (let i = 0; i < nums.length; i++) {
        curSum += nums[i];
        if (curSum >= x) return i + 1;
    }
    return -1;
}

module.exports = { earliestPrefixSum };