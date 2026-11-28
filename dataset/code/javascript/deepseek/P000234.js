Here is the JavaScript code for the problem. This code takes two inputs from the user, the number of rows and columns, and the matrix. It then iterates through the rows and columns, and if the matrix[i][j] is 1, it sets all elements in the i-th row and j-th column to 1.

const readline = require('readline');

const rl = readline.createInterface({
    input: process.stdin,
    output: process.stdout
});

let matrix = [];

rl.question('Enter the number of rows: ', (rows) => {
    rl.question('Enter the number of columns: ', (cols) => {
        for(let i = 0; i < rows; i++) {
            matrix[i] = [];
            for(let j = 0; j < cols; j++) {
                matrix[i][j] = 0;
            }
        }

        rl.question('Enter the matrix: ', (input) => {
            let arr = input.split(' ');
            for(let i = 0; i < rows; i++) {
                for(let j = 0; j < cols; j++) {
                    matrix[i][j] = arr[i * cols + j] == 1;
                }
            }

            console.log(matrix);
            rl.close();
        });
    });
});

This code assumes that the matrix is a 2D array, where each row is an array of numbers. It also assumes that the matrix is 0-indexed.