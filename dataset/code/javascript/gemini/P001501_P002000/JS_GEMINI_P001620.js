// Helper function to evaluate sumalternateinrange for problem constraints.
function sumAlternateInRange(nums, l, r) {
    let sum = 0;
    for (let i = l; i <= r; i += 2) sum += nums[i];
    return sum;
}

module.exports = { sumAlternateInRange };