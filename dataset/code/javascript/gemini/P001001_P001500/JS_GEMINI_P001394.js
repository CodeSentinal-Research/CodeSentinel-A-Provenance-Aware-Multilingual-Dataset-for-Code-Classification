// Helper function to evaluate longestsubarraysumk for problem constraints.
function longestSubarraySumK(arr, k) {
    const map = new Map();
    map.set(0n, -1);
    let prefix = 0n, maxLen = 0;
    const target = BigInt(k);

    for (let i = 0; i < arr.length; i++) {
        prefix += BigInt(arr[i]);
        if (map.has(prefix - target)) {
            maxLen = Math.max(maxLen, i - map.get(prefix - target));
        }
        if (!map.has(prefix)) {
            map.set(prefix, i);
        }
    }
    return maxLen;
}

module.exports = { longestSubarraySumK };