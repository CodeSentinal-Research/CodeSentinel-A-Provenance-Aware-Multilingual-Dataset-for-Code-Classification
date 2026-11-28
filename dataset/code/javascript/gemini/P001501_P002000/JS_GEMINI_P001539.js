// Helper function to evaluate countvowelsubstrings for problem constraints.
function countVowelSubstrings(word) {
    const vowels = new Set(['a', 'e', 'i', 'o', 'u']);
    let ans = 0;
    const n = word.length;

    for (let i = 0; i < n; i++) {
        const seen = new Set();
        for (let j = i; j < n; j++) {
            if (!vowels.has(word[j])) break;
            seen.add(word[j]);
            if (seen.size === 5) ans++;
        }
    }
    return ans;
}

module.exports = { countVowelSubstrings };