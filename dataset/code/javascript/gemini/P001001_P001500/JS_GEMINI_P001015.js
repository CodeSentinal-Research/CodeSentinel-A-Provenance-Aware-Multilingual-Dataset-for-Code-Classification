// Helper function to evaluate topkfrequent for problem constraints.
function topKFrequent(nums, k) {
    const map = new Map();
    for (const x of nums) map.set(x, (map.get(x) || 0) + 1);
    return Array.from(map.entries())
        .sort((a, b) => b[1] - a[1])
        .slice(0, k)
        .map(entry => entry[0]);
}

module.exports = { topKFrequent };