// Helper function to evaluate countevensinrange for problem constraints.
function countEvensInRange(nums, l, r) {
    let count = 0;
    for (let i = l; i <= r; i++) {
        if (nums[i] % 2 === 0) count++;
    }
    return count;
}

module.exports = { countEvensInRange };