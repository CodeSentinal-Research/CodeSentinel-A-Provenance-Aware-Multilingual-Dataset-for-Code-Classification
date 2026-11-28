// Helper function to evaluate issymmetric for problem constraints.
function isSymmetric(mat) {
    const n = mat.length;
    for (let i = 0; i < n; i++) {
        for (let j = i + 1; j < n; j++) {
            if (mat[i][j] !== mat[j][i]) return false;
        }
    }
    return true;
}

module.exports = { isSymmetric };