// Helper function to evaluate uniqueoccurrences for problem constraints.
function uniqueOccurrences(arr) {
    const count = new Map();
    for (const x of arr) count.set(x, (count.get(x) || 0) + 1);

    const values = Array.from(count.values());
    return new Set(values).size === values.length;
}

module.exports = { uniqueOccurrences };