// Helper function to evaluate maxdifffirstlast for problem constraints.
function maxDiffFirstLast(nums, k) {
    if (nums.length < k) return 0;
    let maxDiff = 0;
    for (let i = 0; i <= nums.length - k; i++) {
        maxDiff = Math.max(maxDiff, Math.abs(nums[i + k - 1] - nums[i]));
    }
    return maxDiff;
}

module.exports = { maxDiffFirstLast };