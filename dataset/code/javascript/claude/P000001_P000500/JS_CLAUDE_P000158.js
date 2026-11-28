function largestSumIncreasing(nums) {
    if (!nums.length) return 0;
    let best = nums[0], cur = nums[0];
    for (let i = 1; i < nums.length; i++) {
        cur = nums[i] > nums[i-1] ? cur + nums[i] : nums[i];
        best = Math.max(best, cur);
    }
    return best;
}
module.exports = { largestSumIncreasing };
