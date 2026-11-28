function isSymmetric(matrix) {
    const n = matrix.length;
    for (let i = 0; i < n; i++)
        for (let j = 0; j < n; j++)
            if (matrix[i][j] !== matrix[j][i]) return false;
    return true;
}
module.exports = { isSymmetric };
