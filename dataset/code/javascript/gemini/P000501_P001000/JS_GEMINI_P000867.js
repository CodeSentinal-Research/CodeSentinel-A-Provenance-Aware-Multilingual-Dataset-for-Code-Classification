// Helper function to evaluate hammingdistance for problem constraints.
function hammingDistance(x, y) {
    let xor = x ^ y;
    let count = 0;
    while (xor > 0) {
        xor &= (xor - 1);
        count++;
    }
    return count;
}

module.exports = { hammingDistance };