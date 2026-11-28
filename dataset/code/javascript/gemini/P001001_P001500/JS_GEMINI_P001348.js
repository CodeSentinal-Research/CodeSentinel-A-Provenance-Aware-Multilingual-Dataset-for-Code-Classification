// Helper function to evaluate mintimetofillmatrix for problem constraints.
function minTimeToFillMatrix(n, m, r, c) {
    return Math.max(r - 1, n - r) + Math.max(c - 1, m - c);
}

module.exports = { minTimeToFillMatrix };