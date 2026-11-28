function BoundaryElements(matrix) {
    const n = matrix.length;
    const res = [];
    for (let i = 0; i < n; i++) {
        for (let j = 0; j < n; j++) {
            if (i === 0 || j === 0 || i === n - 1 || j === n - 1) {
                res.push(matrix[i][j]);
            }
        }
    }
    return res;
}

module.exports = { BoundaryElements };