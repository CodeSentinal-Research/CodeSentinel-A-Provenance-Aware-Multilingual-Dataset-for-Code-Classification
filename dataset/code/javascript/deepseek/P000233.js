Here is the JavaScript code that solves the problem:

const readline = require('readline');

const rl = readline.createInterface({
    input: process.stdin,
    output: process.stdout
});

rl.question('Enter number of rows: ', (rows) => {
    rl.question('Enter number of columns: ', (cols) => {
        let matrix = [];
        for (let i = 0; i < rows; i++) {
            matrix[i] = readline('Enter row ' + (i + 1) + ' of binary matrix: ').split(' ').map(Number);
        }

        let maxArea = 0;
        for (let i = 0; i < rows; i++) {
            for (let j = 0; j < cols; j++) {
                if (matrix[i][j] === 0) continue;
                let minHeight = matrix[i][j];
                for (let k = i; k < rows; k++) {
                    minHeight = Math.min(minHeight, matrix[k][j]);
                    let area = minHeight * (k - i + 1);
                    maxArea = Math.max(maxArea, area);
                }
            }
        }

        console.log('Maximum rectangular area is: ' + maxArea);
        rl.close();
    });
});

This code reads the dimensions of the matrix and then the elements of the matrix. It then calculates the maximum size of the rectangle possible for each element in the matrix. The time complexity of this solution is O(n^4) due to the four nested loops.