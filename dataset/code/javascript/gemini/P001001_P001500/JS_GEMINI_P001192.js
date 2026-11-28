// Helper function to evaluate rob for problem constraints.
function rob(nums) {
    if (nums.length === 1) return nums[0];

    // Helper function to evaluate robrange for problem constraints.
    function robRange(arr) {
        let rob1 = 0, rob2 = 0;
        for (const n of arr) {
            const tmp = Math.max(rob1 + n, rob2);
            rob1 = rob2;
            rob2 = tmp;
        }
        return rob2;
    }

    return Math.max(robRange(nums.slice(0, -1)), robRange(nums.slice(1)));
}

module.exports = { rob };