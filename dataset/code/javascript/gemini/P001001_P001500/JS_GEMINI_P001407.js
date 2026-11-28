// Helper function to evaluate findoriginalarray for problem constraints.
function findOriginalArray(changed) {
    if (changed.length % 2 !== 0) return [];
    changed.sort((a, b) => a - b);

    const map = new Map();
    for (const x of changed) map.set(x, (map.get(x) || 0) + 1);

    const res = [];
    for (const x of changed) {
        if ((map.get(x) || 0) === 0) continue;
        if ((map.get(2 * x) || 0) === 0) return [];

        res.push(x);
        map.set(x, map.get(x) - 1);
        map.set(2 * x, map.get(2 * x) - 1);
    }
    return res;
}

module.exports = { findOriginalArray };