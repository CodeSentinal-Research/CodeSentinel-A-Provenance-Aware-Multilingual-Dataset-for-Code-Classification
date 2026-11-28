// Helper function to evaluate numberofarithmeticslices for problem constraints.
function numberOfArithmeticSlices(nums) {
    const n = nums.length;
    if (n < 3) return 0;
    let dp = 0, total = 0;
    for (let i = 2; i < n; i++) {
        if (nums[i] - nums[i - 1] === nums[i - 1] - nums[i - 2]) {
            dp += 1;
            total += dp;
        } else {
            dp = 0;
        }
    }
    return total;
}

module.exports = { numberOfArithmeticSlices };