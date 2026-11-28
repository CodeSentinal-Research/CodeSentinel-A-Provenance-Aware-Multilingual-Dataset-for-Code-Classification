// Helper function to evaluate sumbetweenpositions for problem constraints.
function sumBetweenPositions(nums, l, r) {
    let sum = 0;
    for (let i = l; i <= r; i++) sum += nums[i];
    return sum;
}

module.exports = { sumBetweenPositions };