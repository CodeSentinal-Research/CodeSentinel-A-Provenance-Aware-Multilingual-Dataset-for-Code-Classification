function firstNonRepeating(arr) {
    const freq = new Map();
    for (const x of arr) freq.set(x, (freq.get(x) || 0) + 1);
    for (const x of arr) {
        if (freq.get(x) === 1) return x;
    }
    return 0;
}

module.exports = { firstNonRepeating };