function getFrequencies(s) {
    const freq = {};
    for (const c of s) {
        freq[c] = (freq[c] || 0) + 1;
    }
    return freq;
}

module.exports = { getFrequencies };