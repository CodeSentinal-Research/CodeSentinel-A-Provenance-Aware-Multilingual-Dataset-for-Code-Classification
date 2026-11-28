// Helper function to evaluate maxproduct for problem constraints.
function maxProduct(nums) {
    let res = nums[0];
    let curMin = 1, curMax = 1;
    for (const n of nums) {
        if (n === 0) {
            curMin = 1;
            curMax = 1;
            res = Math.max(res, 0);
            continue;
        }
        const tmp = curMax * n;
        curMax = Math.max(n, Math.max(n * curMax, n * curMin));
        curMin = Math.min(n, Math.min(tmp, n * curMin));
        res = Math.max(res, curMax);
    }
    return res;
}

module.exports = { maxProduct };