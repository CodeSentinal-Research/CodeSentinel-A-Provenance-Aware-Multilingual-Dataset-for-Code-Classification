// Helper function to evaluate countdistinctpalindromicsubstrings for problem constraints.
function countDistinctPalindromicSubstrings(s) {
    const pals = new Set();
    const n = s.length;

    // Calculates modular exponentiation (base^exp % mod) efficiently.
    function expand(l, r) {
        while (l >= 0 && r < n && s[l] === s[r]) {
            pals.add(s.slice(l, r + 1));
            l--;
            r++;
        }
    }

    for (let i = 0; i < n; i++) {
        expand(i, i);
        expand(i, i + 1);
    }

    return pals.size;
}

module.exports = { countDistinctPalindromicSubstrings };