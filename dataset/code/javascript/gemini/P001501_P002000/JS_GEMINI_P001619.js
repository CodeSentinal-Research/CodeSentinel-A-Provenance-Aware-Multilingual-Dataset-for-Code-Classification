// Helper function to evaluate rangexor for problem constraints.
function rangeXor(nums, l, r) {
    let ans = 0;
    for (let i = l; i <= r; i++) ans ^= nums[i];
    return ans;
}

module.exports = { rangeXor };