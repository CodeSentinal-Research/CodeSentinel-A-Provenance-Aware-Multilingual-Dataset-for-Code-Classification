function rotateMatrix(A) {
    const n = A.length;
    for (let i = 0; i < Math.floor(n / 2); i++) {
        for (let j = i; j < n - 1 - i; j++) {
            const temp = A[i][j];
            A[i][j] = A[n - 1 - j][i];
            A[n - 1 - j][i] = A[n - 1 - i][n - 1 - j];
            A[n - 1 - i][n - 1 - j] = A[j][n - 1 - i];
            A[j][n - 1 - i] = temp;
        }
    }
    return A;
}

module.exports = { rotateMatrix };
