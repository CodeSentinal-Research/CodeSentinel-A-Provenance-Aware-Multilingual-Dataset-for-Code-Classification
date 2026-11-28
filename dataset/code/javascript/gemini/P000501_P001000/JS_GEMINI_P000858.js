// Helper function to evaluate findposition for problem constraints.
function findPosition(n) {
    if (n <= 0 || (n & (n - 1)) !== 0) return -1;
    let pos = 1;
    while ((n & 1) === 0) {
        n >>= 1;
        pos++;
    }
    return pos;
}

module.exports = { findPosition };