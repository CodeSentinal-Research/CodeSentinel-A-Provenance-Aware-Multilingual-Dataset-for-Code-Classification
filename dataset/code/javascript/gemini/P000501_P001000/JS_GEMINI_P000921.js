// Helper function to evaluate digitfrequency for problem constraints.
function digitFrequency(n) {
    const freq = new Array(10).fill(0);
    const s = Math.abs(n).toString();
    for (const ch of s) {
        freq[parseInt(ch, 10)]++;
    }
    return freq;
}

module.exports = { digitFrequency };