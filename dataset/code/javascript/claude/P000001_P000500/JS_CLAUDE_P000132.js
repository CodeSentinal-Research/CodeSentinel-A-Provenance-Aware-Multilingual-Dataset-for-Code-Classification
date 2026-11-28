function equilibriumIndex(nums) {
    let total = nums.reduce((a, b) => a + b, 0);
    let leftSum = 0;
    for (let i = 0; i < nums.length; i++) {
        total -= nums[i];
        if (leftSum === total) return i;
        leftSum += nums[i];
    }
    return -1;
}
module.exports = { equilibriumIndex };
