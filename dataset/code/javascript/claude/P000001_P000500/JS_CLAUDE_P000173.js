function maxDifference(nums) {
    let minVal = nums[0], maxDiff = -Infinity;
    for (let i = 1; i < nums.length; i++) {
        maxDiff = Math.max(maxDiff, nums[i] - minVal);
        minVal = Math.min(minVal, nums[i]);
    }
    return maxDiff;
}
module.exports = { maxDifference };
