// Helper function to evaluate parentindex for problem constraints.
function parentIndex(i) {
    if (i <= 0) return -1;
    return Math.floor((i - 1) / 2);
}

module.exports = { parentIndex };