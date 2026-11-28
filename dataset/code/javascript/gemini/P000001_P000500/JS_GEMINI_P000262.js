function nonrepeatingCharacter(s) {
    const freq = new Map();
    for (const c of s) freq.set(c, (freq.get(c) || 0) + 1);
    for (const c of s) {
        if (freq.get(c) === 1) return c;
    }
    return '$';
}

module.exports = { nonrepeatingCharacter };