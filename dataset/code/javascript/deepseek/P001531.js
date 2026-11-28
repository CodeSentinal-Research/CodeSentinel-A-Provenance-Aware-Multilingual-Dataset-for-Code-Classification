function longestSubstringWithoutRepeatingCharacters(s) {
    let map = new Map();
    let maxLen = 0;
    let start = 0;
    for (let i = 0; i < s.length; i++) {
        if (map.has(s.charAt(i))) {
            start = Math.max(start, map.get(s.charAt(i)) + 1);
        }
        map.set(s.charAt(i), i);
        maxLen = Math.max(maxLen, i - start + 1);
    }
    return maxLen;
}