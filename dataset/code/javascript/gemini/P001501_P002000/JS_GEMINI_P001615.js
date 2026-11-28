// Helper function to evaluate numsubmatrixsumtarget for problem constraints.
function numSubmatrixSumTarget(matrix, target) {
    const m = matrix.length, n = matrix[0].length;
    let ans = 0;

    for (let i = 0; i < m; i++) {
        for (let j = 1; j < n; j++) {
            matrix[i][j] += matrix[i][j - 1];
        }
    }

    for (let c1 = 0; c1 < n; c1++) {
        for (let c2 = c1; c2 < n; c2++) {
            const count = new Map();
            count.set(0, 1);
            let cur = 0;

            for (let r = 0; r < m; r++) {
                cur += matrix[r][c2] - (c1 > 0 ? matrix[r][c1 - 1] : 0);
                ans += (count.get(cur - target) || 0);
                count.set(cur, (count.get(cur) || 0) + 1);
            }
        }
    }
    return ans;
}

module.exports = { numSubmatrixSumTarget };