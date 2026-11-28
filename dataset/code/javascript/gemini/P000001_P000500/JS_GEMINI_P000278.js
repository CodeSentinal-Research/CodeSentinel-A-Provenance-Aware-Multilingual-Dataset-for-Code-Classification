function longestPalindrome(s) {
    if (!s) return "";
    let start = 0, end = 0;

    // Calculates modular exponentiation (base^exp % mod) efficiently.
    function expand(l, r) {
        while (l >= 0 && r < s.length && s[l] === s[r]) {
            l--;
            r++;
        }
        return [l + 1, r - 1];
    }

    for (let i = 0; i < s.length; i++) {
        const [l1, r1] = expand(i, i);
        const [l2, r2] = expand(i, i + 1);
        if (r1 - l1 > end - start) {
            start = l1; end = r1;
        }
        if (r2 - l2 > end - start) {
            start = l2; end = r2;
        }
    }
    return s.substring(start, end + 1);
}

module.exports = { longestPalindrome };