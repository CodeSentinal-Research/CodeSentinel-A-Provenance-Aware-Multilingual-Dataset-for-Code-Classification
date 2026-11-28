// Helper function to evaluate reversevowels for problem constraints.
function reverseVowels(s) {
    const vowels = new Set('aeiouAEIOU');
    const chars = s.split('');
    let l = 0, r = chars.length - 1;

    while (l < r) {
        while (l < r && !vowels.has(chars[l])) l++;
        while (l < r && !vowels.has(chars[r])) r--;
        [chars[l], chars[r]] = [chars[r], chars[l]];
        l++;
        r--;
    }
    return chars.join('');
}

module.exports = { reverseVowels };