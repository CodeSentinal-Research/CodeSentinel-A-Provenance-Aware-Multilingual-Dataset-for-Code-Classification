// Helper function to evaluate longestsemirepetitivesubstring for problem constraints.
function longestSemiRepetitiveSubstring(s) {
    const n = s.length;
    let ans = 1, l = 0, lastRepeat = 0;

    for (let r = 1; r < n; r++) {
        if (s[r] === s[r - 1]) {
            if (lastRepeat > 0) l = lastRepeat;
            lastRepeat = r;
        }
        ans = Math.max(ans, r - l + 1);
    }
    return ans;
}

module.exports = { longestSemiRepetitiveSubstring };