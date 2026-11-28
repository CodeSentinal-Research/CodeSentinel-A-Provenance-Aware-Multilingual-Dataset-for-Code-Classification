// Helper function to evaluate maxdistinctelements for problem constraints.
function maxDistinctElements(arr, k) {
    const map = new Map();
    for (const x of arr) map.set(x, (map.get(x) || 0) + 1);
    const duplicates = [];
    for (const cnt of map.values()) {
        if (cnt > 1) duplicates.push(cnt - 1);
    }
    duplicates.sort((a, b) => a - b);

    while (duplicates.length > 0 && k > 0) {
        const c = duplicates[0];
        if (k >= c) {
            k -= c;
            duplicates.shift();
        } else {
            duplicates[0] -= k;
            k = 0;
        }
    }

    let distinct = map.size;
    if (k > 0) distinct -= k;
    return Math.max(0, distinct);
}

module.exports = { maxDistinctElements };