Here is a simple JavaScript code that reads the matrix dimensions, then the matrix itself and prints all the boundary elements.

let readline = require('readline');

const rl = readline.createInterface({
  input: process.stdin,
  output: process.stdout
});

let rowsCols = rl.question('Enter rows and cols: ', (rowsCols) => {
  let matrix = [];

  rowsCols.split(' ').forEach((row) => {
    row = parseInt(row);
    matrix.push(row.toString().split(' ').map(Number));
  });

  for(let i = 0; i < rowsCols[0]; i++){
    console.log(matrix[0][i]);
  }

  for(let i = 0; i < rowsCols[1]; i++){
    console.log(matrix[i][rowsCols[1] - 1]);
  }

  console.log(matrix[rowsCols[0] - 1][0]);

  if(rowsCols[0] * rowsCols[1] > 1){
    console.log(matrix[rowsCols[0] - 1][rowsCols[1] - 1]);
  }

  rl.close();
});

This code reads the dimensions and matrix from the user, and then prints all the boundary elements. The boundary elements are the first and last elements of each row and the first and last elements of each column.