// Helper function to evaluate firstmissingpositive for problem constraints.
function firstMissingPositive(nums) {
    const set = new Set(nums);
    let i = 1;
    // Shrink window from the left while duplicate element exists
    while (set.has(i)) i++;
    return i;
}

module.exports = { firstMissingPositive };