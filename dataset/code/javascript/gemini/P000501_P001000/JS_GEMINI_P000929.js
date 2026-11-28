// Helper function to evaluate matrixaddition for problem constraints.
function matrixAddition(a, b) {
    const r = a.length, c = a[0].length;
    const res = [];
    for (let i = 0; i < r; i++) {
        const row = [];
        for (let j = 0; j < c; j++) {
            row.push(a[i][j] + b[i][j]);
        }
        res.push(row);
    }
    return res;
}

module.exports = { matrixAddition };