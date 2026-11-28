// Helper function to evaluate longestsubstringatmostkvowels for problem constraints.
function longestSubstringAtMostKVowels(s, k) {
    const vowels = new Set('aeiouAEIOU');
    let l = 0, vCount = 0, maxLen = 0;

    for (let r = 0; r < s.length; r++) {
        if (vowels.has(s[r])) vCount++;
        while (vCount > k) {
            if (vowels.has(s[l++])) vCount--;
        }
        maxLen = Math.max(maxLen, r - l + 1);
    }
    return maxLen;
}

module.exports = { longestSubstringAtMostKVowels };