// Helper function to evaluate topkfrequent for problem constraints.
function topKFrequent(nums, k) {
    const count = new Map();
    for (const n of nums) count.set(n, (count.get(n) || 0) + 1);

    const sorted = Array.from(count.entries()).sort((a, b) => b[1] - a[1]);
    return sorted.slice(0, k).map(item => item[0]);
}

module.exports = { topKFrequent };