// Helper function to evaluate lengthoflongestsubstring for problem constraints.
function lengthOfLongestSubstring(s) {
    const lastPos = new Map();
    let l = 0, maxLen = 0;

    for (let r = 0; r < s.length; r++) {
        const c = s[r];
        if (lastPos.has(c) && lastPos.get(c) >= l) {
            l = lastPos.get(c) + 1;
        }
        lastPos.set(c, r);
        maxLen = Math.max(maxLen, r - l + 1);
    }
    return maxLen;
}

module.exports = { lengthOfLongestSubstring };