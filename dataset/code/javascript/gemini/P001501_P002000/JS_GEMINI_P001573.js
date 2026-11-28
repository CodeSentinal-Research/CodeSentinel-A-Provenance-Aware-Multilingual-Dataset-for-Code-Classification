// Helper function to evaluate countdivisiblesumwindows for problem constraints.
function countDivisibleSumWindows(nums, k, d) {
    if (nums.length < k) return 0;
    let curSum = 0;
    for (let i = 0; i < k; i++) curSum += nums[i];
    let ans = curSum % d === 0 ? 1 : 0;

    for (let i = k; i < nums.length; i++) {
        curSum += nums[i] - nums[i - k];
        if (curSum % d === 0) ans++;
    }
    return ans;
}

module.exports = { countDivisibleSumWindows };