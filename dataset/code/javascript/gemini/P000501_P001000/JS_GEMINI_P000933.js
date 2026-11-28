// Helper function to evaluate isidentitymatrix for problem constraints.
function isIdentityMatrix(mat) {
    const n = mat.length;
    for (let i = 0; i < n; i++) {
        for (let j = 0; j < n; j++) {
            const exp = (i === j) ? 1 : 0;
            if (mat[i][j] !== exp) return false;
        }
    }
    return true;
}

module.exports = { isIdentityMatrix };