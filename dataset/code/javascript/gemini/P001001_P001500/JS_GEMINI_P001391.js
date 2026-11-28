// Helper function to evaluate subarraysum for problem constraints.
function subarraySum(nums, k) {
    const map = new Map();
    map.set(0, 1);
    let prefix = 0, count = 0;

    for (const x of nums) {
        prefix += x;
        count += (map.get(prefix - k) || 0);
        map.set(prefix, (map.get(prefix) || 0) + 1);
    }
    return count;
}

module.exports = { subarraySum };