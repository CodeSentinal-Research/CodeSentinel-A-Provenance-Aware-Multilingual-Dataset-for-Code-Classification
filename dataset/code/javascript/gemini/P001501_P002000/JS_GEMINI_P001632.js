// Helper function to evaluate largestsquaresumlek for problem constraints.
function largestSquareSumLeK(mat, k) {
    const m = mat.length, n = mat[0].length;
    const p = Array.from({ length: m + 1 }, () => new Array(n + 1).fill(0));

    for (let i = 0; i < m; i++) {
        for (let j = 0; j < n; j++) {
            p[i + 1][j + 1] = mat[i][j] + p[i][j + 1] + p[i + 1][j] - p[i][j];
        }
    }

    let maxSide = 0;
    for (let side = 1; side <= Math.min(m, n); side++) {
        for (let i = 0; i <= m - side; i++) {
            for (let j = 0; j <= n - side; j++) {
                const sum = p[i + side][j + side] - p[i][j + side] - p[i + side][j] + p[i][j];
                if (sum <= k) maxSide = Math.max(maxSide, side);
            }
        }
    }
    return maxSide;
}

module.exports = { largestSquareSumLeK };