function smallestSubarraySum(nums) {
    let minSum = nums[0], cur = nums[0];
    for (let i = 1; i < nums.length; i++) {
        cur = Math.min(nums[i], cur + nums[i]);
        minSum = Math.min(minSum, cur);
    }
    return minSum;
}
module.exports = { smallestSubarraySum };
