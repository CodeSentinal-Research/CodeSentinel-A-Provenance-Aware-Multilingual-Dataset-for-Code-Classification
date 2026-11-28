function frequency(arr) {
    const freq = {};
    for (const x of arr) freq[x] = (freq[x] || 0) + 1;
    return freq;
}

module.exports = { frequency };
