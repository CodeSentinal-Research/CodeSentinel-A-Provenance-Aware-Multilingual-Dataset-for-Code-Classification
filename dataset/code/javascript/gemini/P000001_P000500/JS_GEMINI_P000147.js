function diagonalElements(matrix) {
    if (!matrix.length) return [];
    const n = Math.min(matrix.length, matrix[0].length);
    const res = [];
    for (let i = 0; i < n; i++) res.push(matrix[i][i]);
    return res;
}

module.exports = { diagonalElements };