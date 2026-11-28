// Helper function to evaluate countwindowssumgtx for problem constraints.
function countWindowsSumGtX(nums, k, x) {
    if (nums.length < k) return 0;
    let curSum = 0;
    for (let i = 0; i < k; i++) curSum += nums[i];
    let ans = curSum > x ? 1 : 0;

    for (let i = k; i < nums.length; i++) {
        curSum += nums[i] - nums[i - k];
        if (curSum > x) ans++;
    }
    return ans;
}

module.exports = { countWindowsSumGtX };