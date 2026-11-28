// Helper function to evaluate rob for problem constraints.
function rob(nums) {
    let rob1 = 0, rob2 = 0;
    for (const n of nums) {
        const tmp = Math.max(rob1 + n, rob2);
        rob1 = rob2;
        rob2 = tmp;
    }
    return rob2;
}

module.exports = { rob };