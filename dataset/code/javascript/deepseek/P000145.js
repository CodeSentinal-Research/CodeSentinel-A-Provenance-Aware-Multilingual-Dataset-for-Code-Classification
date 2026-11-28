Here is a JavaScript solution for your problem:

const readline = require('readline');

const rl = readline.createInterface({
    input: process.stdin,
    output: process.stdout
});

let matrix = [];

rl.question('Enter the number of rows (1 <= n <= 50): ', (rows) => {
    rl.question('Enter the number of columns (1 <= n <= 50): ', (cols) => {
        rl.question('Enter the target element to search for: ', (target) => {
            matrix = [];
            for (let i = 0; i < rows; i++) {
                matrix[i] = [];
                for (let j = 0; j < cols; j++) {
                    matrix[i][j] = rl.question('Enter element for [' + i + '][' + j + ']: ');
                }
            }
            let result = searchMatrix(matrix, rows, cols, target);
            console.log(result ? 'Found' : 'Not Found');
            rl.close();
        });
    });
});

function searchMatrix(matrix, rows, cols, target) {
    let left = 0, right = rows * cols - 1;
    while (left <= right) {
        let mid = Math.floor((left + right) / 2);
        if (matrix[mid / cols][mid % cols] == target)
            return true;
        else if (matrix[mid / cols][mid % cols] < target)
            left = mid + 1;
        else
            right = mid - 1;
    }
    return false;
}

This code first reads the number of rows and columns from the user. Then it reads the target element to search for. The matrix is then read and the search function is called with the matrix, rows, columns, and target as arguments. The search function uses binary search to find the target in the sorted 2D matrix. If the target is found, it returns true, otherwise it returns false.