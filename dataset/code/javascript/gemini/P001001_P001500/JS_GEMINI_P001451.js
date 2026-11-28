// Helper function to evaluate countpairsxor for problem constraints.
function countPairsXor(arr, k) {
    const map = new Map();
    let ans = 0;

    for (const x of arr) {
        ans += (map.get(x ^ k) || 0);
        map.set(x, (map.get(x) || 0) + 1);
    }
    return ans;
}

module.exports = { countPairsXor };