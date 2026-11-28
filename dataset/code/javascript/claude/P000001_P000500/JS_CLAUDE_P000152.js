function minProduct(nums) {
    nums = [...nums].sort((a, b) => a - b);
    const n = nums.length;
    return Math.min(nums[0]*nums[1], nums[0]*nums[n-1], nums[n-2]*nums[n-1]);
}
module.exports = { minProduct };
