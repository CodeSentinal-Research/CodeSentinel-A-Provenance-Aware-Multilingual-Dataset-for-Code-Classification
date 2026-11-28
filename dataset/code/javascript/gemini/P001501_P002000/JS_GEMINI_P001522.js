// Helper function to evaluate minoperations for problem constraints.
function minOperations(nums, x) {
    const total = nums.reduce((a, b) => a + b, 0);
    const target = total - x;

    if (target < 0) return -1;
    if (target === 0) return nums.length;

    let curSum = 0, maxLen = -1, l = 0;
    for (let r = 0; r < nums.length; r++) {
        curSum += nums[r];
        while (curSum > target && l <= r) {
            curSum -= nums[l++];
        }
        if (curSum === target) {
            maxLen = Math.max(maxLen, r - l + 1);
        }
    }
    return maxLen !== -1 ? nums.length - maxLen : -1;
}

module.exports = { minOperations };