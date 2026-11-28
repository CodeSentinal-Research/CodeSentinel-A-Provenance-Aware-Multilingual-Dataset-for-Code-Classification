const readline = require('readline');

const rl = readline.createInterface({
    input: process.stdin,
    output: process.stdout
});

let N;
rl.once('line', (line) => {
    N = parseInt(line);
    let matrix = [];
    for(let i = 0; i < N; i++) {
        matrix.push(rl.readLine().split(' ').map(Number));
    }
    rl.close();
    console.log(isOrthogonal(matrix) ? 'Yes' : 'No');
});

function isOrthogonal(matrix) {
    // calculate transpose of matrix
    let transpose = matrix[0].map((col, i) => matrix.map(row => row[i]));

    // calculate product of matrix and transpose
    for(let i = 0; i < matrix.length; i++) {
        for(let j = 0; j < matrix.length; j++) {
            if (matrix[i].dot(matrix[j]) !== transpose[i].dot(transpose[j])) {
                return false;
            }
        }
    }
    return true;
}

This code reads the size of the matrix from the standard input, then reads the matrix. It then uses a helper function, `isOrthogonal`, to check whether the matrix is orthogonal. This function first calculates the transpose of the matrix, then calculates the dot product of each row of the matrix with each column of the transpose. If any pair of these dot products are not equal to 1, then the matrix is not orthogonal, and the function returns false. If all pairs of dot products are equal to 1, then the matrix is orthogonal, and the function returns true.