// Helper function to evaluate matrixblocksum for problem constraints.
function matrixBlockSum(mat, k) {
    const m = mat.length, n = mat[0].length;
    const p = Array.from({ length: m + 1 }, () => new Array(n + 1).fill(0));

    for (let i = 0; i < m; i++) {
        for (let j = 0; j < n; j++) {
            p[i + 1][j + 1] = mat[i][j] + p[i][j + 1] + p[i + 1][j] - p[i][j];
        }
    }

    const res = Array.from({ length: m }, () => new Array(n).fill(0));
    for (let i = 0; i < m; i++) {
        for (let j = 0; j < n; j++) {
            const r1 = Math.max(0, i - k), c1 = Math.max(0, j - k);
            const r2 = Math.min(m - 1, i + k), c2 = Math.min(n - 1, j + k);
            res[i][j] = p[r2 + 1][c2 + 1] - p[r1][c2 + 1] - p[r2 + 1][c1] + p[r1][c1];
        }
    }
    return res;
}

module.exports = { matrixBlockSum };