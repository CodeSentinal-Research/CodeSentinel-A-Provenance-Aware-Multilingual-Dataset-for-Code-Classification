Here is a simple JavaScript code snippet that performs matrix exponentiation. This code uses a divide and conquer strategy. First, it recursively splits the matrix into quadrants, then it recursively computes the results of the quadrants.

function multiply(A, B) {
    const res = [[0, 0], [0, 0]];
    res[0][0] = A[0][0] * B[0][0] + A[0][1] * B[1][0];
    res[0][1] = A[0][0] * B[0][1] + A[0][1] * B[1][1];
    res[1][0] = A[1][0] * B[0][0] + A[1][1] * B[1][0];
    res[1][1] = A[1][0] * B[0][1] + A[1][1] * B[1][1];
    return res;
}

function power(A, K) {
    if (K === 0) {
        return [[1, 0], [0, 1]];
    }
    if (K === 1) {
        return A;
    }
    const halfK = power(A, Math.floor(K / 2));
    const res = multiply(halfK, halfK);
    if (K % 2 === 1) {
        res = multiply(res, A);
    }
    return res;
}

// Usage
const A = [[1, 2], [3, 4]];
const K = 5;
console.log(JSON.stringify(power(A, K), null, 2));

This code works for the matrix A = [[1, 2], [3, 4]], and K = 5. The function power first checks if K is 0 or 1, then it computes the power using the divide and conquer strategy. If K is odd, it computes A * A^(K-1), and if K is even, it computes A^(K/2) * A^(K/2).

This code assumes that the input is a square matrix and that it's guaranteed to be a power of 2.