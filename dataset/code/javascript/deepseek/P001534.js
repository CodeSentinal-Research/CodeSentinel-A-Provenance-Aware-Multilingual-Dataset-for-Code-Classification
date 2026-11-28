function longestSubstringWithAtMostTwoDistinctChars(s) {
    let left = 0, right = 0;
    let map = new Map();
    let maxLen = 0;

    while (right < s.length) {
        map.set(s[right], right);
        if (map.size === 3) {
            let oldest = Math.min(...map.values());
            map.delete(s[oldest]);
            left = oldest + 1;
        }
        maxLen = Math.max(maxLen, right - left + 1);
        right++;
    }

    return maxLen;
}