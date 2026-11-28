// Helper function to evaluate heapheight for problem constraints.
function heapHeight(n) {
    if (n <= 0) return 0;
    return Math.floor(Math.log2(n));
}

module.exports = { heapHeight };