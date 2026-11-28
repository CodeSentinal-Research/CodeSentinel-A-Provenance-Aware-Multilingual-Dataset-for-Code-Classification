// Helper function to evaluate containsnearbyduplicate for problem constraints.
function containsNearbyDuplicate(nums, k) {
    const seen = new Map();
    for (let i = 0; i < nums.length; i++) {
        if (seen.has(nums[i]) && i - seen.get(nums[i]) <= k) {
            return true;
        }
        seen.set(nums[i], i);
    }
    return false;
}

module.exports = { containsNearbyDuplicate };