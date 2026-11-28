Here is the JavaScript code for the problem:

const readline = require('readline');

const rl = readline.createInterface({
    input: process.stdin,
    output: process.stdout
});

let rows, cols;

rl.question('Enter rows and cols: ', (c) => {
    [rows, cols] = c.split(' ').map(x => parseInt(x));
    const matrix = [];
    for (let i = 0; i < rows; i++) {
        matrix[i] = rl.question(`Enter row ${i + 1}: `, (c) => {
            matrix[i] = c.split(' ').map(x => parseInt(x));
            if (i !== rows - 1) rl.question('');
        });
    }

    const dp = Array(rows).fill(0).map(() => Array(cols).fill(0));
    const dp2 = Array(rows).fill(0).map(() => Array(cols).fill(0));
    dp[0][0] = matrix[0][0];
    dp2[rows - 1][cols - 1] = matrix[rows - 1][cols - 1];

    for (let i = 0; i < rows; i++) {
        for (let j = 0; j < cols; j++) {
            if (i > 0) dp[i][j] = Math.max(dp[i][j], dp[i - 1][j] + matrix[i][j]);
            if (j > 0) dp[i][j] = Math.max(dp[i][j], dp[i][j - 1] + matrix[i][j]);
        }
    }

    for (let i = rows - 1; i >= 0; i--) {
        for (let j = cols - 1; j >= 0; j--) {
            if (i < rows - 1) dp2[i][j] = Math.max(dp2[i][j], dp2[i + 1][j] + matrix[i][j]);
            if (j < cols - 1) dp2[i][j] = Math.max(dp2[i][j], dp2[i][j + 1] + matrix[i][j]);
        }
    }

    console.log(Math.max(dp[rows - 1][cols - 1], dp2[0][0]));

    rl.close();
});

This program will ask for the number of rows and columns, and then for each row. It reads the matrix row by row, and then calculates the maximum sum path in the matrix from top-left to bottom-right. It uses dynamic programming to solve this problem.