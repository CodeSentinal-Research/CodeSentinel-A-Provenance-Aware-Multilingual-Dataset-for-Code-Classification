// Helper function to evaluate countzerosinrange for problem constraints.
function countZerosInRange(nums, l, r) {
    let count = 0;
    for (let i = l; i <= r; i++) {
        if (nums[i] === 0) count++;
    }
    return count;
}

module.exports = { countZerosInRange };