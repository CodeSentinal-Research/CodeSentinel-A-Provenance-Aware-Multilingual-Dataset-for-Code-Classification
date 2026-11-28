Here is the JavaScript code to print the elements of a matrix in diagonal order.

const readline = require('readline');

const rl = readline.createInterface({
    input: process.stdin,
    output: process.stdout
});

let matrix = [];

rl.question('Enter number of rows and cols (separated by space): ', (rowsCols) => {
    let rowsColsArray = rowsCols.split(' ');
    matrix = [];
    for(let i = 0; i < rowsColsArray[0]; i++) {
        matrix[i] = [];
        for(let j = 0; j < rowsColsArray[1]; j++) {
            matrix[i][j] = rl.question('Enter element for row ' + (i+1) + ' and col ' + (j+1) + ' (separated by space): ');
        }
    }
    printDiagonalOrder(matrix, rowsColsArray[0], rowsColsArray[1]);
    rl.close();
});

function printDiagonalOrder(matrix, m, n) {
    for(let i = 0; i < m; i++) {
        let sum = matrix[i][0];
        for(let j = 1; j < n; j++) {
            sum += matrix[i][j];
        }
        console.log(sum);
    }

    for(let i = 1; i < m; i++) {
        let sum = matrix[0][i];
        for(let j = 1; j < n; j++) {
            sum += matrix[j][i];
        }
        console.log(sum);
    }

    let sum = matrix[0][0];
    for(let i = 1; i < m; i++) {
        sum += matrix[i][i];
    }
    console.log(sum);

    sum = 0;
    for(let i = 1; i < m; i++) {
        sum += matrix[i][n - i - 1];
    }
    console.log(sum);
}

This program asks the user for the number of rows and columns, then asks for the elements of the matrix one by one. After that, it prints the elements in diagonal order.