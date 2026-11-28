// Helper function to evaluate minpairsum for problem constraints.
function minPairSum(nums) {
    nums.sort((a, b) => a - b);
    const n = nums.length;
    let maxPair = 0;
    for (let i = 0; i < Math.floor(n / 2); i++) {
        maxPair = Math.max(maxPair, nums[i] + nums[n - 1 - i]);
    }
    return maxPair;
}

module.exports = { minPairSum };