// Helper function to evaluate shortestprefixgtx for problem constraints.
function shortestPrefixGtX(nums, x) {
    let curSum = 0;
    for (let i = 0; i < nums.length; i++) {
        curSum += nums[i];
        if (curSum > x) return i + 1;
    }
    return -1;
}

module.exports = { shortestPrefixGtX };