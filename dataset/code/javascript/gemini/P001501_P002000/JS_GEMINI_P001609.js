// Helper function to evaluate pivotindex for problem constraints.
function pivotIndex(nums) {
    const total = nums.reduce((a, b) => a + b, 0);
    let left = 0;

    for (let i = 0; i < nums.length; i++) {
        if (left === total - left - nums[i]) return i;
        left += nums[i];
    }
    return -1;
}

module.exports = { pivotIndex };