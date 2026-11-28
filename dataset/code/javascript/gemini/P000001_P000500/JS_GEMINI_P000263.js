function lastNonRepeatingCharacter(s) {
    const freq = new Map();
    for (const c of s) freq.set(c, (freq.get(c) || 0) + 1);
    for (let i = s.length - 1; i >= 0; i--) {
        if (freq.get(s[i]) === 1) return s[i];
    }
    return '$';
}

module.exports = { lastNonRepeatingCharacter };