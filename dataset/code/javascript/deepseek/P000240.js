let matrix = [];
let row = parseInt(readline());
let col = parseInt(readline());

for (let i = 0; i < row; i++) {
    matrix[i] = readline().split(" ").map(Number);
}

let sum = 0;

for (let i = 0; i < row; i++) {
    for (let j = 0; j < col; j++) {
        if (i === 0 || i === row - 1 || j === 0 || j === col - 1) {
            sum += matrix[i][j];
        }
    }
}

console.log(sum);

In this code, we first read the number of rows and columns. Then, we read the matrix in a 2D array. We iterate over each element in the matrix, and check if the element is a boundary element (i.e., it's on the boundary of the matrix). If it is, we add it to the sum.