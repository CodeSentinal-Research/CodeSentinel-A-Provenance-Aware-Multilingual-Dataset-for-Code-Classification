// Helper function to evaluate construct2dprefix for problem constraints.
function construct2DPrefix(mat) {
    const m = mat.length, n = mat[0].length;
    const p = Array.from({ length: m }, () => new Array(n).fill(0));

    for (let i = 0; i < m; i++) {
        for (let j = 0; j < n; j++) {
            p[i][j] = mat[i][j];
            if (i > 0) p[i][j] += p[i - 1][j];
            if (j > 0) p[i][j] += p[i][j - 1];
            if (i > 0 && j > 0) p[i][j] -= p[i - 1][j - 1];
        }
    }
    return p;
}

module.exports = { construct2DPrefix };