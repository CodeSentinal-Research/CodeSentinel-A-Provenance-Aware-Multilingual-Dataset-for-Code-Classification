function findSubstring(s, words) {
    const wordBag = new Set(words);
    const wordLen = words[0].length;
    const result = [];
    for (let i = 0; i <= s.length - wordLen * words.length; i++) {
        const seen = new Set();
        let matches = 0;
        for (let j = i; j < i + wordLen * words.length; j += wordLen) {
            const currWord = s.substring(j, j + wordLen);
            if (!wordBag.has(currWord)) {
                break;
            }
            seen.add(currWord);
            if (seen.size === wordBag.size) {
                matches++;
                result.push(i);
                break;
            }
        }
        if (matches) {
            i += wordLen - 1;
        }
    }
    if (!result.length) {
        return -1;
    }
    return result;
}