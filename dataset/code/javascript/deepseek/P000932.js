function traceOfSquareMatrix(N, A) {
    // Check if matrix is valid
    if (N < 1 || N > 1000) {
        throw new Error('Invalid input: N must be between 1 and 1000');
    }

    if (!Array.isArray(A) || A.length !== N || A.length !== N) {
        throw new Error('Invalid input: A must be a square matrix');
    }

    for (let i = 0; i < N; i++) {
        if (typeof A[i] !== 'number' || Array.isArray(A[i])) {
            throw new Error('Invalid input: A must be a 2D array');
        }
    }

    let trace = 0;
    for (let i = 0; i < N; i++) {
        trace += A[i][i];
    }

    return trace;
}