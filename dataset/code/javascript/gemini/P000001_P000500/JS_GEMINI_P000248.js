function sumMatrix(A, B) {
    if (A.length !== B.length || A[0].length !== B[0].length) return [];
    return A.map((row, i) => row.map((val, j) => val + B[i][j]));
}

module.exports = { sumMatrix };