function minimizeArrayValue(nums) {
    let ans = 0;
    let total = 0;
    for (let i = 0; i < nums.length; i++) {
        total += nums[i];
        ans = Math.max(ans, Math.ceil(total / (i + 1)));
    }
    return ans;
}

module.exports = { minimizeArrayValue };