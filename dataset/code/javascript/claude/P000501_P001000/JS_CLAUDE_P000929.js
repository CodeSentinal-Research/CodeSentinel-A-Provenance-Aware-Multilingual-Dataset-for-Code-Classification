function addMatrices(A, B) {
    return A.map((row, i) => row.map((val, j) => val + B[i][j]));
}

module.exports = { addMatrices };
