function characterReplacement(s, k) {
    const count = new Map();
    let maxFreq = 0, l = 0;

    for (let r = 0; r < s.length; r++) {
        count.set(s[r], (count.get(s[r]) || 0) + 1);
        maxFreq = Math.max(maxFreq, count.get(s[r]));

        if ((r - l + 1) - maxFreq > k) {
            count.set(s[l], count.get(s[l]) - 1);
            l++;
        }
    }
    return s.length - l;
}

module.exports = { characterReplacement };