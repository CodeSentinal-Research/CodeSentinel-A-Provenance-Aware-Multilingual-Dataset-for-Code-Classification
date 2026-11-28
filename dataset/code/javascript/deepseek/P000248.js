const readline = require('readline');

const rl = readline.createInterface({
    input: process.stdin,
    output: process.stdout
});

rl.question('Enter the number of rows and columns for the matrices: ', (nrows) => {

    const matrix1 = [];
    const matrix2 = [];

    rl.setPrompt('Enter the elements for the first matrix: ');

    for(let i=0; i<nrows; i++){
        matrix1.push(rl.readline('').split(' ').map(Number));
    }

    rl.setPrompt('Enter the elements for the second matrix: ');

    for(let i=0; i<nrows; i++){
        matrix2.push(rl.readline('').split(' ').map(Number));
    }

    const sumMatrix = [];

    for(let i=0; i<nrows; i++){
        sumMatrix.push(matrix1[i].map((num, j) => num + matrix2[i][j]));
    }

    console.log('The sum of the matrices is: ');
    console.log(sumMatrix.map(row => row.join(' ')).join('\n'));

    rl.close();
});