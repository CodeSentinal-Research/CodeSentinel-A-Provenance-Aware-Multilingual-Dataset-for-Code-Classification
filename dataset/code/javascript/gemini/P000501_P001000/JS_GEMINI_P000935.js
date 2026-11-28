// Helper function to evaluate diagonalsum for problem constraints.
function diagonalSum(mat) {
    const n = mat.length;
    let total = 0;
    for (let i = 0; i < n; i++) {
        total += mat[i][i];
        if (i !== n - 1 - i) {
            total += mat[i][n - 1 - i];
        }
    }
    return total;
}

module.exports = { diagonalSum };