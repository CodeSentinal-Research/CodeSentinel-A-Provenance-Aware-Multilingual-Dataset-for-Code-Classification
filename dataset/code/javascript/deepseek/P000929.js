Here is a simple JavaScript code to add two matrices:

function matrixAddition(N, A, B) {
    var result = [];
    for (var i = 0; i < N; i++) {
        result[i] = [];
        for (var j = 0; j < N; j++) {
            result[i][j] = A[i][j] + B[i][j];
        }
    }
    return result;
}

This code works by iterating over the rows and columns of the matrices, and adding the corresponding elements from the two matrices.

To use this function, you can pass in the dimensions of the matrix (N) and the two matrices (A and B). The function will return the resulting matrix. For example:

var A = [[1, 2], [3, 4]];
var B = [[5, 6], [7, 8]];
var result = matrixAddition(2, A, B);
console.log(result);  // Output: [[6, 8], [10, 12]]

This code assumes that the input matrices are in the correct format (i.e., they are arrays of arrays, where each inner array represents a row in the matrix).