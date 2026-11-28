function countVowels(s) {
    const vowels = new Set(['a', 'e', 'i', 'o', 'u', 'A', 'E', 'I', 'O', 'U']);
    let count = 0;
    for (const c of s) {
        if (vowels.has(c)) count++;
    }
    return count;
}

module.exports = { countVowels };