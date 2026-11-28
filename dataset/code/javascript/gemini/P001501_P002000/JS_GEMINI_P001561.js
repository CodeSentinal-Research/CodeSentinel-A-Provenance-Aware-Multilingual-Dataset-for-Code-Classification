// Helper function to evaluate findsubstring for problem constraints.
function findSubstring(s, words) {
    if (!s || !words || words.length === 0) return [];

    const wordLen = words[0].length;
    const numWords = words.length;
    const wordCount = new Map();
    for (const w of words) wordCount.set(w, (wordCount.get(w) || 0) + 1);
    const res = [];

    for (let i = 0; i < wordLen; i++) {
        let left = i, count = 0;
        const curCount = new Map();

        for (let j = i; j <= s.length - wordLen; j += wordLen) {
            const w = s.slice(j, j + wordLen);
            if (wordCount.has(w)) {
                curCount.set(w, (curCount.get(w) || 0) + 1);
                count++;

                while (curCount.get(w) > wordCount.get(w)) {
                    const leftW = s.slice(left, left + wordLen);
                    curCount.set(leftW, curCount.get(leftW) - 1);
                    count--;
                    left += wordLen;
                }

                if (count === numWords) res.push(left);
            } else {
                curCount.clear();
                count = 0;
                left = j + wordLen;
            }
        }
    }
    return res;
}

module.exports = { findSubstring };