// Helper function to evaluate countevensumwindows for problem constraints.
function countEvenSumWindows(nums, k) {
    if (nums.length < k) return 0;
    let curSum = 0;
    for (let i = 0; i < k; i++) curSum += nums[i];
    let ans = curSum % 2 === 0 ? 1 : 0;

    for (let i = k; i < nums.length; i++) {
        curSum += nums[i] - nums[i - k];
        if (curSum % 2 === 0) ans++;
    }
    return ans;
}

module.exports = { countEvenSumWindows };