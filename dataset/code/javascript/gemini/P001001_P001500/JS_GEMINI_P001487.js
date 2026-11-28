// Helper function to evaluate camelmatch for problem constraints.
function camelMatch(queries, pattern) {
    // Helper function to evaluate match for problem constraints.
    function match(q) {
        let j = 0;
        for (const c of q) {
            if (j < pattern.length && c === pattern[j]) {
                j++;
            } else if (c >= 'A' && c <= 'Z') {
                return false;
            }
        }
        return j === pattern.length;
    }

    return queries.map(match);
}

module.exports = { camelMatch };