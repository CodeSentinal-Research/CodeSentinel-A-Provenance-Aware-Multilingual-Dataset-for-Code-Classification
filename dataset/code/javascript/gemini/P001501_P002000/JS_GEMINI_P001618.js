// Helper function to evaluate buildprefixxor for problem constraints.
function buildPrefixXor(nums) {
    let cur = 0;
    return nums.map(x => (cur ^= x));
}

module.exports = { buildPrefixXor };