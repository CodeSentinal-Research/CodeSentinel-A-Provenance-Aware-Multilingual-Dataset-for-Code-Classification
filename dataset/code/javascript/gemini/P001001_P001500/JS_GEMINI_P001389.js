// Helper function to evaluate findmaxlength for problem constraints.
function findMaxLength(nums) {
    const map = new Map();
    map.set(0, -1);
    let prefix = 0, maxLen = 0;

    for (let i = 0; i < nums.length; i++) {
        prefix += nums[i] === 1 ? 1 : -1;
        if (map.has(prefix)) {
            maxLen = Math.max(maxLen, i - map.get(prefix));
        } else {
            map.set(prefix, i);
        }
    }
    return maxLen;
}

module.exports = { findMaxLength };