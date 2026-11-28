// Helper function to evaluate rangeaverage for problem constraints.
function rangeAverage(nums, l, r) {
    let sum = 0;
    for (let i = l; i <= r; i++) sum += nums[i];
    return sum / (r - l + 1);
}

module.exports = { rangeAverage };