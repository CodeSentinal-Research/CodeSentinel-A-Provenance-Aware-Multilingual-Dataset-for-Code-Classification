function minProductSubarray(nums) {
    let minProd = nums[0], maxProd = nums[0], ans = nums[0];
    for (let i = 1; i < nums.length; i++) {
        const x = nums[i];
        const p1 = minProd * x, p2 = maxProd * x;
        minProd = Math.min(x, p1, p2);
        maxProd = Math.max(x, p1, p2);
        if (minProd < ans) ans = minProd;
    }
    return ans;
}

module.exports = { minProductSubarray };