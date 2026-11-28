// Helper function to evaluate maxsubarraylen for problem constraints.
function maxSubArrayLen(nums, k) {
    const map = new Map();
    map.set(0, -1);
    let prefix = 0, maxLen = 0;

    for (let i = 0; i < nums.length; i++) {
        prefix += nums[i];
        if (map.has(prefix - k)) {
            maxLen = Math.max(maxLen, i - map.get(prefix - k));
        }
        if (!map.has(prefix)) {
            map.set(prefix, i);
        }
    }
    return maxLen;
}

module.exports = { maxSubArrayLen };