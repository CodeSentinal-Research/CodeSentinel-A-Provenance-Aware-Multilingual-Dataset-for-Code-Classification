// Helper function to evaluate largestsumafterknegations for problem constraints.
function largestSumAfterKNegations(nums, k) {
    nums.sort((a, b) => a - b);
    for (let i = 0; i < nums.length && k > 0; i++) {
        if (nums[i] < 0) {
            nums[i] = -nums[i];
            k--;
        }
    }
    nums.sort((a, b) => a - b);
    if (k % 2 === 1) {
        nums[0] = -nums[0];
    }
    return nums.reduce((a, b) => a + b, 0);
}

module.exports = { largestSumAfterKNegations };