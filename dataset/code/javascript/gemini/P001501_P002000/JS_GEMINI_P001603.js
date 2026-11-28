// Helper function to evaluate smallestprefixatleastx for problem constraints.
function smallestPrefixAtLeastX(nums, x) {
    let cur = 0;
    for (let i = 0; i < nums.length; i++) {
        cur += nums[i];
        if (cur >= x) return i + 1;
    }
    return -1;
}

module.exports = { smallestPrefixAtLeastX };