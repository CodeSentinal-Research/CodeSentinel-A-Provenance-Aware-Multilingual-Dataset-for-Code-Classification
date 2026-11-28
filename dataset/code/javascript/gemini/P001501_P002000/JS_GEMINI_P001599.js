// Helper function to evaluate countmultiplesinrange for problem constraints.
function countMultiplesInRange(nums, l, r, k) {
    let count = 0;
    for (let i = l; i <= r; i++) {
        if (nums[i] % k === 0) count++;
    }
    return count;
}

module.exports = { countMultiplesInRange };