function smallestSumSubarray(nums) {
    let minSum = nums[0], curSum = nums[0];
    for (let i = 1; i < nums.length; i++) {
        curSum = Math.min(nums[i], curSum + nums[i]);
        if (curSum < minSum) minSum = curSum;
    }
    return minSum;
}

module.exports = { smallestSumSubarray };