// Helper function to evaluate maxvowels for problem constraints.
function maxVowels(s, k) {
    const vowels = new Set(['a', 'e', 'i', 'o', 'u']);
    let curVowels = 0;
    for (let i = 0; i < k; i++) if (vowels.has(s[i])) curVowels++;
    let maxVowels = curVowels;

    for (let i = k; i < s.length; i++) {
        if (vowels.has(s[i])) curVowels++;
        if (vowels.has(s[i - k])) curVowels--;
        if (curVowels > maxVowels) maxVowels = curVowels;
    }
    return maxVowels;
}

module.exports = { maxVowels };