function longestSubstringWithKDistinctCharacters(str, k) {
    let maxLen = 0;
    let distinctCount = 0;
    let start = 0;
    let map = {};

    for (let end = 0; end < str.length; end++) {
        if (!map[str[end]]) {
            distinctCount++;
        }
        map[str[end]] = true;

        if (distinctCount === k) {
            maxLen = Math.max(maxLen, end - start + 1);
            start = end - distinctCount + 1;
            distinctCount = 0;
            map = {};
        }
    }

    maxLen = Math.max(maxLen, end - start + 1);
    return maxLen;
}