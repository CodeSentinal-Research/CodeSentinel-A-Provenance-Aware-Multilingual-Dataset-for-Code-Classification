function transpose(A) {
    const r = A.length, c = A[0].length;
    const T = Array.from({ length: c }, () => new Array(r));
    for (let i = 0; i < r; i++)
        for (let j = 0; j < c; j++)
            T[j][i] = A[i][j];
    return T;
}

module.exports = { transpose };
