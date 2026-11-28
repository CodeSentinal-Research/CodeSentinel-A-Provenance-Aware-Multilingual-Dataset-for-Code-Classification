// Helper function to evaluate lastinternalnode for problem constraints.
function lastInternalNode(n) {
    if (n <= 1) return -1;
    return Math.floor(n / 2) - 1;
}

module.exports = { lastInternalNode };