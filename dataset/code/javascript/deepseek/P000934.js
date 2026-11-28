Here is the JavaScript code for rotating the matrix 90 degrees clockwise:

function rotateMatrix(N, A) {
    for (let x = 0; x < N / 2; x++) {
        for (let y = x; y < N - x - 1; y++) {
            let temp = A[x][y];
            A[x][y] = A[N - 1 - y][x];
            A[N - 1 - y][x] = A[N - 1 - x][N - 1 - y];
            A[N - 1 - x][N - 1 - y] = A[y][N - 1 - x];
            A[y][N - 1 - x] = temp;
        }
    }
    return A;
}

This function works by rotating each layer of the matrix. The inner loop iterates over each element in the current layer, and the outer loop iterates over each layer. This creates the effect of rotating the matrix 90 degrees clockwise.

Please note that this function modifies the input matrix `A` in-place. If you don't want to modify the original matrix, you should make a copy of it before calling this function.