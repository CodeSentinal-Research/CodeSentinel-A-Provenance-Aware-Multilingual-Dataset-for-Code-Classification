function diagonalSum(A) {
    const n = A.length;
    let sum = 0;
    for (let i = 0; i < n; i++) {
        sum += A[i][i];
        if (i !== n - 1 - i) sum += A[i][n - 1 - i];
    }
    return sum;
}

module.exports = { diagonalSum };
