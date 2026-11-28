// Helper function to evaluate minsumwindow for problem constraints.
function minSumWindow(nums, k) {
    if (nums.length < k) return 0;
    let curSum = 0;
    for (let i = 0; i < k; i++) curSum += nums[i];
    let minSum = curSum;

    for (let i = k; i < nums.length; i++) {
        curSum += nums[i] - nums[i - k];
        if (curSum < minSum) minSum = curSum;
    }
    return minSum;
}

module.exports = { minSumWindow };