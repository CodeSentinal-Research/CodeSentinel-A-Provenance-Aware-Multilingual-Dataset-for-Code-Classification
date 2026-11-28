// Helper function to evaluate countequalxorpairs for problem constraints.
function countEqualXorPairs(arr) {
    const map = new Map();
    map.set(0, 1);
    let prefix = 0, ans = 0;

    for (const x of arr) {
        prefix ^= x;
        ans += (map.get(prefix) || 0);
        map.set(prefix, (map.get(prefix) || 0) + 1);
    }
    return ans;
}

module.exports = { countEqualXorPairs };