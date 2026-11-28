// Helper function to evaluate countdistinctsubstrings for problem constraints.
function countDistinctSubstrings(s) {
    const set = new Set();
    const n = s.length;
    for (let i = 0; i < n; i++) {
        for (let j = i + 1; j <= n; j++) {
            set.add(s.slice(i, j));
        }
    }
    return set.size + 1;
}

module.exports = { countDistinctSubstrings };