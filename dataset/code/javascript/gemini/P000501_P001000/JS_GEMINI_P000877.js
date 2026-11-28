// Helper function to evaluate minbitflips for problem constraints.
function minBitFlips(start, goal) {
    let xor = start ^ goal;
    let count = 0;
    while (xor > 0) {
        xor &= (xor - 1);
        count++;
    }
    return count;
}

module.exports = { minBitFlips };