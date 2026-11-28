// Helper function to evaluate findlucky for problem constraints.
function findLucky(arr) {
    const map = new Map();
    for (const x of arr) map.set(x, (map.get(x) || 0) + 1);

    let maxLucky = -1;
    for (const [k, v] of map.entries()) {
        if (k === v) {
            if (k > maxLucky) maxLucky = k;
        }
    }
    return maxLucky;
}

module.exports = { findLucky };