// Helper function to evaluate containsduplicate for problem constraints.
function containsDuplicate(nums) {
    return new Set(nums).size !== nums.length;
}

module.exports = { containsDuplicate };