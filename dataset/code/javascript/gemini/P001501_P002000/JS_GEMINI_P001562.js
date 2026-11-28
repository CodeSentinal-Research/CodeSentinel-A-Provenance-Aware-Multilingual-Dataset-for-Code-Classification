// Helper function to evaluate longestsubstringkdistinct for problem constraints.
function longestSubstringKDistinct(s, k) {
    const count = new Map();
    let l = 0, maxLen = -1;

    for (let r = 0; r < s.length; r++) {
        const c = s[r];
        count.set(c, (count.get(c) || 0) + 1);
        while (count.size > k) {
            const left = s[l++];
            count.set(left, count.get(left) - 1);
            if (count.get(left) === 0) count.delete(left);
        }
        if (count.size === k) {
            maxLen = Math.max(maxLen, r - l + 1);
        }
    }
    return maxLen;
}

module.exports = { longestSubstringKDistinct };