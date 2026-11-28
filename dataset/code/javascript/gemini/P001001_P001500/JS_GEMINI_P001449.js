// Helper function to evaluate findmaxk for problem constraints.
function findMaxK(nums) {
    const set = new Set(nums);
    let maxK = -1;
    for (const x of nums) {
        if (x > 0 && set.has(-x)) {
            if (x > maxK) maxK = x;
        }
    }
    return maxK;
}

module.exports = { findMaxK };