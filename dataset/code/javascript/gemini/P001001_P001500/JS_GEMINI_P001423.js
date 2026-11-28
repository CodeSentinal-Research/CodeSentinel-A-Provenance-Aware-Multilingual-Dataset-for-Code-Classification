// Helper function to evaluate findandreplacepattern for problem constraints.
function findAndReplacePattern(words, pattern) {
    // Helper function to evaluate getnorm for problem constraints.
    function getNorm(s) {
        const seen = new Map();
        return s.split('').map(c => {
            if (!seen.has(c)) seen.set(c, seen.size);
            return seen.get(c);
        }).join(',');
    }

    const patNorm = getNorm(pattern);
    return words.filter(w => getNorm(w) === patNorm);
}

module.exports = { findAndReplacePattern };