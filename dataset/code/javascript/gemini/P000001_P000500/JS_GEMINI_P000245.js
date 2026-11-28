function lowerTriangular(matrix) {
    const n = matrix.length;
    for (let i = 0; i < n; i++) {
        for (let j = i + 1; j < n; j++) {
            matrix[i][j] = 0;
        }
    }
    return matrix;
}

module.exports = { lowerTriangular };