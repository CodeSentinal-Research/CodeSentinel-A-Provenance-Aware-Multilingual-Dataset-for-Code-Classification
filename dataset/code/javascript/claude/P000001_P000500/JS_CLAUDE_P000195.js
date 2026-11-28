function cyclicRotate(nums) {
    if (!nums.length) return nums;
    return [nums[nums.length-1], ...nums.slice(0,-1)];
}
module.exports = { cyclicRotate };
