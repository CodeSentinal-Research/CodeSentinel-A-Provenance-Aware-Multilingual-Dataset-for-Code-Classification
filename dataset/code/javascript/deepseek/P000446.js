Sure, here is a JavaScript function that does the job.

function searchMatrix(matrix, target) {
    let row = 0;
    let col = matrix[0].length - 1;

    while (row < matrix.length && col >= 0) {
        if (matrix[row][col] === target) {
            return "Found";
        } else if (matrix[row][col] > target) {
            col--;
        } else {
            row++;
        }
    }
    return "Not Found";
}

// Testing the function
const matrix = [[1, 4, 7, 11, 15], [2, 5, 8, 12, 19], [3, 6, 9, 16, 22], [10, 13, 14, 17, 24], [18, 21, 23, 26, 30]];
const target = 15;
console.log(searchMatrix(matrix, target)); // "Found"

target = 20;
console.log(searchMatrix(matrix, target)); // "Not Found"

This function uses two pointers, one at the top-right corner of the matrix and the other at the bottom-left corner. It compares the target value with the current value in the top-right corner. If the target is larger, it moves to the left. If the target is smaller, it moves down. It keeps doing this until it finds the target or exhausts the matrix.