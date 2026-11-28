// Helper function to evaluate countbinarysubstrings for problem constraints.
function countBinarySubstrings(s) {
    let prev = 0, cur = 1, ans = 0;
    for (let i = 1; i < s.length; i++) {
        if (s[i] === s[i - 1]) {
            cur++;
        } else {
            ans += Math.min(prev, cur);
            prev = cur;
            cur = 1;
        }
    }
    return ans + Math.min(prev, cur);
}

module.exports = { countBinarySubstrings };