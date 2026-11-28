// Helper function to evaluate matrixmultiplication for problem constraints.
function matrixMultiplication(a, b) {
    const r1 = a.length, c1 = a[0].length;
    const c2 = b[0].length;
    const res = Array.from({ length: r1 }, () => new Array(c2).fill(0));
    for (let i = 0; i < r1; i++) {
        for (let k = 0; k < c1; k++) {
            for (let j = 0; j < c2; j++) {
                res[i][j] += a[i][k] * b[k][j];
            }
        }
    }
    return res;
}

module.exports = { matrixMultiplication };