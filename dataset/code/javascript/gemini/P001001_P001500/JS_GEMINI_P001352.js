// Helper function to evaluate splitstring for problem constraints.
function splitString(s) {
    // Helper function to evaluate backtrack for problem constraints.
    function backtrack(idx, prev, count) {
        if (idx === s.length) return count >= 2;
        for (let i = idx + 1; i <= s.length; i++) {
            const val = BigInt(s.slice(idx, i));
            if (prev === -1n || val === prev - 1n) {
                if (backtrack(i, val, count + 1)) return true;
            }
        }
        return false;
    }

    return backtrack(0, -1n, 0);
}

module.exports = { splitString };