function countVowels(s) {
    const vowels = 'aeiouAEIOU';
    let count = 0;
    for (const c of s) if (vowels.includes(c)) count++;
    return count;
}

module.exports = { countVowels };
