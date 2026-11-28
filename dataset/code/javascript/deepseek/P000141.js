Here is the JavaScript code for the problem:

let N = parseInt(readline());
let matrix = [];
for(let i = 0; i < N; i++) {
    matrix[i] = readline().split(' ').map(Number);
}

for(let i = 0; i < N; i++) {
    for(let j = i; j < N - i - 1; j++) {
        let temp = matrix[i][j];
        matrix[i][j] = matrix[N - 1 - j][i];
        matrix[N - 1 - j][i] = matrix[N - 1 - i][N - 1 - j];
        matrix[N - 1 - i][N - 1 - j] = matrix[j][N - 1 - i];
        matrix[j][N - 1 - i] = temp;
    }
}

for(let row of matrix) {
    console.log(row.join(' '));
}

This code reads the size of the matrix (N) from the standard input. Then it reads the matrix elements one by one. After that, it rotates the matrix 90 degrees clockwise. Finally, it prints the rotated matrix.