function countEqualVowelsConsonants(s) {
    const vowels = new Set(['a', 'e', 'i', 'o', 'u', 'A', 'E', 'I', 'O', 'U']);
    let prefix = 0;
    let count = 0;
    const freq = new Map();
    freq.set(0, 1);
    for (const ch of s) {
        if (/[a-zA-Z]/.test(ch)) {
            prefix += vowels.has(ch) ? 1 : -1;
            count += (freq.get(prefix) || 0);
            freq.set(prefix, (freq.get(prefix) || 0) + 1);
        }
    }
    return count;
}

module.exports = { countEqualVowelsConsonants };