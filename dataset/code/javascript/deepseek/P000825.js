Here is the JavaScript code for the problem:

function searchMatrix(matrix, target) {
    if (!matrix || !matrix.length || !matrix[0].length) {
        return false;
    }

    let row = 0;
    let col = matrix[0].length - 1;

    while (row < matrix.length && col >= 0) {
        if (matrix[row][col] === target) {
            return true;
        } else if (matrix[row][col] > target) {
            col--;
        } else {
            row++;
        }
    }

    return false;
}

This function starts from the top right corner of the matrix and moves towards the left, checking each element. If the current element is the target, we return true. If the current element is greater than the target, we move to the next column (col--). If the current element is less than the target, we move down (row++). If we reach the end of the matrix, we return false.

You can use the function like this:

let matrix = [
    [1, 4, 7, 11, 15],
    [2, 5, 8, 12, 19],
    [3, 6, 9, 16, 22],
    [10, 13, 14, 17, 24],
    [18, 21, 23, 26, 30]
];

console.log(searchMatrix(matrix, 5)); // true
console.log(searchMatrix(matrix, 20)); // false