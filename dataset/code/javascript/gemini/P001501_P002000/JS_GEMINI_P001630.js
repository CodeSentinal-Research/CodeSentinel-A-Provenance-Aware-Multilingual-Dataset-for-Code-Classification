// Helper function to evaluate minopsequalizeprefix for problem constraints.
function minOpsEqualizePrefix(nums) {
    let ops = 0;
    for (let i = 1; i < nums.length; i++) {
        ops += Math.abs(nums[i] - nums[i - 1]);
    }
    return ops;
}

module.exports = { minOpsEqualizePrefix };