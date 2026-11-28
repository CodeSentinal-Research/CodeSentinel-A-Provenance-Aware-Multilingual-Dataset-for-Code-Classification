// Helper function to evaluate maxuniquesplit for problem constraints.
function maxUniqueSplit(s) {
    const seen = new Set();

    // Helper function to evaluate backtrack for problem constraints.
    function backtrack(idx) {
        if (idx === s.length) return 0;
        let maxCount = 0;
        for (let i = idx + 1; i <= s.length; i++) {
            const sub = s.slice(idx, i);
            if (!seen.has(sub)) {
                seen.add(sub);
                maxCount = Math.max(maxCount, 1 + backtrack(i));
                seen.delete(sub);
            }
        }
        return maxCount;
    }

    return backtrack(0);
}

module.exports = { maxUniqueSplit };