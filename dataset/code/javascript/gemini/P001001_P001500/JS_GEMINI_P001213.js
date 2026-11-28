// Helper function to evaluate isscramble for problem constraints.
function isScramble(s1, s2) {
    const memo = new Map();

    // Helper function to evaluate dfs for problem constraints.
    function dfs(a, b) {
        if (a === b) return true;
        if (a.split('').sort().join('') !== b.split('').sort().join('')) return false;

        const key = a + '#' + b;
        if (memo.has(key)) return memo.get(key);

        const n = a.length;
        for (let i = 1; i < n; i++) {
            if (dfs(a.slice(0, i), b.slice(0, i)) && dfs(a.slice(i), b.slice(i))) {
                memo.set(key, true);
                return true;
            }
            if (dfs(a.slice(0, i), b.slice(n - i)) && dfs(a.slice(i), b.slice(0, n - i))) {
                memo.set(key, true);
                return true;
            }
        }
        memo.set(key, false);
        return false;
    }

    return dfs(s1, s2);
}

module.exports = { isScramble };