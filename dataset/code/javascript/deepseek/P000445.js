Here is the JavaScript code that solves the problem:

const readline = require('readline');

const rl = readline.createInterface({
    input: process.stdin,
    output: process.stdout
});

rl.question('Enter rows and columns: ', (rowsCols) => {
    const [rows, cols] = rowsCols.split(' ').map(Number);
    const matrix = [];

    rl.setPrompt('Enter matrix: ');
    for (let i = 0; i < rows; i++) {
        matrix.push(rl.readLine().split(' ').map(Number));
    }

    rl.question('Enter target: ', (target) => {
        const targetNum = Number(target);
        let found = false;

        for (let i = 0; i < rows; i++) {
            for (let j = 0; j < cols; j++) {
                if (matrix[i][j] === targetNum) {
                    console.log('Found');
                    found = true;
                    break;
                }
            }
            if (found) break;
        }

        if (!found) console.log('Not Found');

        rl.close();
    });
});

In this code, we use `readline` module to handle the input and output. We first read the number of rows and columns from the standard input, and then we create a 2D matrix with those dimensions. After that, we read the matrix and target number from the standard input. After that, we iterate through the matrix and check if the target number is present in the matrix. If it is, we print 'Found' and break the loop. If the target number is not found after checking all elements, we print 'Not Found'.