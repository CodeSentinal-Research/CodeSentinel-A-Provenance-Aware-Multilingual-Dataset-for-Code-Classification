function findEquilibrium(nums) {
    let total = nums.reduce((a, b) => a + b, 0), left = 0;
    for (let i = 0; i < nums.length; i++) {
        total -= nums[i];
        if (left === total) return i;
        left += nums[i];
    }
    return -1;
}
module.exports = { findEquilibrium };
