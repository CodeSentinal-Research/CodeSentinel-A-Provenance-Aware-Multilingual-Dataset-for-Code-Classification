// Helper function to evaluate findrepeateddnasequences for problem constraints.
function findRepeatedDnaSequences(s) {
    const seen = new Set();
    const res = new Set();

    for (let i = 0; i <= s.length - 10; i++) {
        const sub = s.slice(i, i + 10);
        if (seen.has(sub)) res.add(sub);
        seen.add(sub);
    }
    return Array.from(res);
}

module.exports = { findRepeatedDnaSequences };