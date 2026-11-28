// Helper function to evaluate countpositivesinrange for problem constraints.
function countPositivesInRange(nums, l, r) {
    let count = 0;
    for (let i = l; i <= r; i++) {
        if (nums[i] > 0) count++;
    }
    return count;
}

module.exports = { countPositivesInRange };