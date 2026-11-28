let N = parseInt(readline());

let matrix = [];

for (let i = 0; i < N; i++) {
    matrix[i] = readline().split(' ').map(Number);
}

matrix.sort((a, b) => a - b);

matrix.forEach(row => console.log(row.join(' ')));

This program will read the size of the matrix from the first line, then read the elements of the matrix. After that, it sorts the matrix in ascending order and prints the sorted elements.