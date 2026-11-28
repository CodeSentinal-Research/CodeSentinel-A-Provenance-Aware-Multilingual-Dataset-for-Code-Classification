// Helper function to evaluate findlhs for problem constraints.
function findLHS(nums) {
    const map = new Map();
    for (const x of nums) map.set(x, (map.get(x) || 0) + 1);

    let ans = 0;
    for (const [x, cnt] of map.entries()) {
        if (map.has(x + 1)) {
            ans = Math.max(ans, cnt + map.get(x + 1));
        }
    }
    return ans;
}

module.exports = { findLHS };