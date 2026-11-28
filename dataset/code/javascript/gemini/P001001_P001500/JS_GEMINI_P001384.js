// Helper function to evaluate findduplicates for problem constraints.
function findDuplicates(nums) {
    const res = [];
    for (const x of nums) {
        const idx = Math.abs(x) - 1;
        if (nums[idx] < 0) {
            res.push(Math.abs(x));
        } else {
            nums[idx] = -nums[idx];
        }
    }
    return res;
}

module.exports = { findDuplicates };