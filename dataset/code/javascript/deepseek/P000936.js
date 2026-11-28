Here is the JavaScript code to check if a given matrix is symmetric about its main diagonal:

function isSymmetric(matrix) {
    for (let i = 0; i < matrix.length; i++) {
        for (let j = 0; j < matrix[i].length; j++) {
            if (matrix[i][j] !== matrix[matrix.length - 1 - i][matrix[i].length - 1 - j]) {
                return false;
            }
        }
    }
    return true;
}

let matrix = [[1, 2, 3], [2, 3, 4], [3, 4, 5]];
console.log(isSymmetric(matrix));

In this code, we iterate over each element in the matrix, comparing it with the element at the position (matrix.length - 1 - i, matrix[i].length - 1 - j). If any pair of elements does not match, we return false. If we finish the iteration without finding any mismatches, we return true.