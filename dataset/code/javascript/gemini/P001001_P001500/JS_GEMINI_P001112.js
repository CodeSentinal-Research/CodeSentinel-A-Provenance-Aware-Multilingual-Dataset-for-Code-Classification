// Helper function to evaluate ladderlength for problem constraints.
function ladderLength(beginWord, endWord, wordList) {
    const words = new Set(wordList);
    if (!words.has(endWord)) return 0;

    const q = [[beginWord, 1]];
    const visited = new Set([beginWord]);

    while (q.length > 0) {
        const [word, len] = q.shift();
        if (word === endWord) return len;
        for (let i = 0; i < word.length; i++) {
            for (let c = 97; c <= 122; c++) {
                const char = String.fromCharCode(c);
                const nextWord = word.slice(0, i) + char + word.slice(i + 1);
                if (words.has(nextWord) && !visited.has(nextWord)) {
                    visited.add(nextWord);
                    q.push([nextWord, len + 1]);
                }
            }
        }
    }
    return 0;
}

module.exports = { ladderLength };