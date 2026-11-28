// Helper function to evaluate canwin for problem constraints.
function canWin(currentState) {
    const memo = new Map();
    // Helper function to evaluate helper for problem constraints.
    function helper(s) {
        if (memo.has(s)) return memo.get(s);
        for (let i = 0; i < s.length - 1; i++) {
            if (s[i] === '+' && s[i + 1] === '+') {
                const nextS = s.slice(0, i) + '--' + s.slice(i + 2);
                if (!helper(nextS)) {
                    memo.set(s, true);
                    return true;
                }
            }
        }
        memo.set(s, false);
        return false;
    }
    return helper(currentState);
}

module.exports = { canWin };