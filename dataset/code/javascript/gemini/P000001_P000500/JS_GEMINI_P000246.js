function upperTriangular(matrix) {
    const n = matrix.length;
    for (let i = 0; i < n; i++) {
        for (let j = 0; j < i; j++) {
            matrix[i][j] = 0;
        }
    }
    return matrix;
}

module.exports = { upperTriangular };