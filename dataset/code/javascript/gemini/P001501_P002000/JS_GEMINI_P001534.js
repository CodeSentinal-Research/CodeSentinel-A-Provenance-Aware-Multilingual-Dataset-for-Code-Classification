// Helper function to evaluate lengthoflongestsubstringtwodistinct for problem constraints.
function lengthOfLongestSubstringTwoDistinct(s) {
    const count = new Map();
    let l = 0, maxLen = 0;

    for (let r = 0; r < s.length; r++) {
        const c = s[r];
        count.set(c, (count.get(c) || 0) + 1);
        while (count.size > 2) {
            count.set(s[l], count.get(s[l]) - 1);
            if (count.get(s[l]) === 0) count.delete(s[l]);
            l++;
        }
        maxLen = Math.max(maxLen, r - l + 1);
    }
    return maxLen;
}

module.exports = { lengthOfLongestSubstringTwoDistinct };