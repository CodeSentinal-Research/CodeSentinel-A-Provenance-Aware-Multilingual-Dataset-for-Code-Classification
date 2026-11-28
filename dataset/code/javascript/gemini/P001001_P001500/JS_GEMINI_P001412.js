// Helper function to evaluate countpairsdiff for problem constraints.
function countPairsDiff(arr, k) {
    const map = new Map();
    for (const x of arr) map.set(x, (map.get(x) || 0) + 1);

    let ans = 0;
    if (k === 0) {
        for (const cnt of map.values()) {
            if (cnt > 1) ans++;
        }
    } else {
        for (const x of map.keys()) {
            if (map.has(x + k)) ans++;
        }
    }
    return ans;
}

module.exports = { countPairsDiff };