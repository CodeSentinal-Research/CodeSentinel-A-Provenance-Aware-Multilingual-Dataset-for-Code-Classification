// Helper function to evaluate countequalinrange for problem constraints.
function countEqualInRange(nums, l, r, x) {
    let count = 0;
    for (let i = l; i <= r; i++) {
        if (nums[i] === x) count++;
    }
    return count;
}

module.exports = { countEqualInRange };