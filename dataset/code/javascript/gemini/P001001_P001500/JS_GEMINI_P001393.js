// Helper function to evaluate checksubarraysum for problem constraints.
function checkSubarraySum(nums, k) {
    const map = new Map();
    map.set(0, -1);
    let prefix = 0;

    for (let i = 0; i < nums.length; i++) {
        prefix = (prefix + nums[i]) % k;
        if (map.has(prefix)) {
            if (i - map.get(prefix) >= 2) return true;
        } else {
            map.set(prefix, i);
        }
    }
    return false;
}

module.exports = { checkSubarraySum };