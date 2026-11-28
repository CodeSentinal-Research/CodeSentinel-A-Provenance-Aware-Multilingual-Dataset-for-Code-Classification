const readline = require('readline');

const rl = readline.createInterface({
    input: process.stdin,
    output: process.stdout
});

let matrix = [];

rl.question('Enter number of rows: ', (rows) => {
    rl.question('Enter number of columns: ', (cols) => {
        matrix = [];
        for (let i = 0; i < rows; i++) {
            matrix[i] = [];
            for (let j = 0; j < cols; j++) {
                matrix[i][j] = rl.question(`Enter element for matrix[${i}][${j}]: `);
            }
        }

        // Sorting matrix
        for (let i = 0; i < rows; i++) {
            matrix[i] = matrix[i].sort((a, b) => a - b);
        }

        matrix.sort((a, b) => a.length - b.length || a.join(' ') < b.join(' '') ? -1 : 1);

        console.log('Sorted matrix:');
        matrix.forEach(row => {
            console.log(row.join(' '));
        });
        rl.close();
    });
});