Here is the JavaScript code to calculate the transpose of a matrix:

function matrixTranspose(N, M, A) {
    if (!(N === M)) {
        throw new Error("Matrix must be square for its transpose");
    }

    var transpose = Array.from(A, () => Array(N).fill(0));

    for (let i = 0; i < N; i++) {
        for (let j = 0; j < M; j++) {
            transpose[j][i] = A[i][j];
        }
    }

    return transpose;
}

In this code, we first make sure that the matrix is square. If not, we throw an error.
Then we create a new matrix of size N×M filled with zeroes.
In the loop, we swap rows and columns of the original matrix, and fill the new matrix with the swapped values.
Finally, we return the new matrix.