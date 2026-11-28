function multiply(A, B) {
    const r1 = A.length, c1 = A[0].length, c2 = B[0].length;
    const C = Array.from({ length: r1 }, () => new Array(c2).fill(0));
    for (let i = 0; i < r1; i++)
        for (let j = 0; j < c2; j++)
            for (let k = 0; k < c1; k++)
                C[i][j] += A[i][k] * B[k][j];
    return C;
}

module.exports = { multiply };
