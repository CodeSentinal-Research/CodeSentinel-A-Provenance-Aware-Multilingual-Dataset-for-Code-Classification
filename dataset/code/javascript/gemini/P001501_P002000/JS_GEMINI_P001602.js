// Helper function to evaluate maxabsprefixsum for problem constraints.
function maxAbsPrefixSum(nums) {
    let cur = 0, maxAbs = 0;
    for (const x of nums) {
        cur += x;
        if (Math.abs(cur) > maxAbs) maxAbs = Math.abs(cur);
    }
    return maxAbs;
}

module.exports = { maxAbsPrefixSum };