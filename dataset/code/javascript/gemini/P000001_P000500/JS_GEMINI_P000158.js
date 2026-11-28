function maxIncreasingSubarraySum(nums) {
    if (!nums.length) return 0;
    let maxSum = nums[0], curSum = nums[0];
    for (let i = 1; i < nums.length; i++) {
        if (nums[i] > nums[i - 1]) {
            curSum += nums[i];
        } else {
            curSum = nums[i];
        }
        if (curSum > maxSum) maxSum = curSum;
    }
    return maxSum;
}

module.exports = { maxIncreasingSubarraySum };