// Helper function to evaluate buildprefixsum for problem constraints.
function buildPrefixSum(nums) {
    let cur = 0;
    return nums.map(x => (cur += x));
}

module.exports = { buildPrefixSum };