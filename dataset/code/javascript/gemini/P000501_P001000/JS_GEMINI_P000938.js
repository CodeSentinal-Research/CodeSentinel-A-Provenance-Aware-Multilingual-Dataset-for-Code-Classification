// Helper function to evaluate multiply for problem constraints.
function multiply(mat1, mat2) {
    const r1 = mat1.length, c1 = mat1[0].length;
    const c2 = mat2[0].length;
    const res = Array.from({ length: r1 }, () => new Array(c2).fill(0));
    for (let i = 0; i < r1; i++) {
        for (let k = 0; k < c1; k++) {
            if (mat1[i][k] !== 0) {
                for (let j = 0; j < c2; j++) {
                    if (mat2[k][j] !== 0) {
                        res[i][j] += mat1[i][k] * mat2[k][j];
                    }
                }
            }
        }
    }
    return res;
}

module.exports = { multiply };