// Helper function to evaluate maxproductwindow for problem constraints.
function maxProductWindow(nums, k) {
    if (nums.length < k) return 0;
    let curProd = 1n;
    for (let i = 0; i < k; i++) curProd *= BigInt(nums[i]);
    let maxProd = curProd;

    for (let i = k; i < nums.length; i++) {
        curProd = (curProd / BigInt(nums[i - k])) * BigInt(nums[i]);
        if (curProd > maxProd) maxProd = curProd;
    }
    return Number(maxProd);
}

module.exports = { maxProductWindow };