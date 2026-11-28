// Helper function to evaluate lengthoflongestsubstring for problem constraints.
function lengthOfLongestSubstring(s) {
    const last = new Map();
    let l = 0, maxLen = 0;
    for (let r = 0; r < s.length; r++) {
        const c = s[r];
        if (last.has(c) && last.get(c) >= l) {
            l = last.get(c) + 1;
        }
        last.set(c, r);
        maxLen = Math.max(maxLen, r - l + 1);
    }
    return maxLen;
}

module.exports = { lengthOfLongestSubstring };