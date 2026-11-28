// Helper function to evaluate findlongestchain for problem constraints.
function findLongestChain(pairs) {
    pairs.sort((a, b) => a[1] - b[1]);
    let cur = -Infinity, ans = 0;
    for (const [x, y] of pairs) {
        if (cur < x) {
            cur = y;
            ans++;
        }
    }
    return ans;
}

module.exports = { findLongestChain };