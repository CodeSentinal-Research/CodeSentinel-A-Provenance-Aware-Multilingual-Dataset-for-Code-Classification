function maxProduct(nums) {
    let best = nums[0], curMax = nums[0], curMin = nums[0];
    for (let i = 1; i < nums.length; i++) {
        const x = nums[i];
        const newMax = Math.max(x, curMax*x, curMin*x);
        curMin = Math.min(x, curMax*x, curMin*x);
        curMax = newMax;
        best = Math.max(best, curMax);
    }
    return best;
}
module.exports = { maxProduct };
