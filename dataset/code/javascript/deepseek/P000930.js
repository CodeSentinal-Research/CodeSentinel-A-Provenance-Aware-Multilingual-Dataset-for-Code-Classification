function matrixProduct(N, M, P) {
    if (!(1 <= N && N <= 100) || !(1 <= M && M <= 100) || !(1 <= P && P <= 100)) {
        throw new Error('N, M, P must be in the range 1 <= N, M, P <= 100');
    }

    let A = [];
    let B = [];
    let C = [];

    for (let i = 0; i < N; i++) {
        A[i] = [];
        B[i] = [];
        C[i] = [];
        for (let j = 0; j < M; j++) {
            A[i][j] = Math.floor(Math.random() * 10);
            B[i][j] = Math.floor(Math.random() * 10);
            C[i][j] = 0;
        }
    }

    for (let i = 0; i < N; i++) {
        for (let j = 0; j < P; j++) {
            for (let k = 0; k < M; k++) {
                C[i][j] += A[i][k] * B[k][j];
            }
        }
    }

    return C;
}