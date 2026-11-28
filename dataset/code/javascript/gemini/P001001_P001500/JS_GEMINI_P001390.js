// Helper function to evaluate maxlenzerosum for problem constraints.
function maxLenZeroSum(arr) {
    const map = new Map();
    map.set(0n, -1);
    let prefix = 0n, maxLen = 0;

    for (let i = 0; i < arr.length; i++) {
        prefix += BigInt(arr[i]);
        if (map.has(prefix)) {
            maxLen = Math.max(maxLen, i - map.get(prefix));
        } else {
            map.set(prefix, i);
        }
    }
    return maxLen;
}

module.exports = { maxLenZeroSum };