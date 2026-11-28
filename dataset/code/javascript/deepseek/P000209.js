Here is a simple JavaScript solution using a 2D array to represent the matrix. The solution first gets the rows and columns from the input, then reads the matrix from the standard input. After that, it rotates the matrix one step clockwise.

const readline = require('readline');

const rl = readline.createInterface({
  input: process.stdin,
  output: process.stdout
});

rl.on('line', function(line) {
  const size = line.split(' ');
  const rows = parseInt(size[0]);
  const cols = parseInt(size[1]);

  const matrix = [];

  for(let i = 0; i < rows; i++) {
    matrix[i] = [];
    for(let j = 0; j < cols; j++) {
      matrix[i][j] = parseInt(rl.readline());
    }
  }

  // transpose matrix
  for(let i = 0; i < rows; i++) {
    for(let j = i; j < cols; j++) {
      [matrix[i][j], matrix[j][i]] = [matrix[j][i], matrix[i][j]];
    }
  }

  // reverse each row
  for(let i = 0; i < rows; i++) {
    matrix[i] = matrix[i].reverse();
  }

  for(let i = 0; i < rows; i++) {
    console.log(matrix[i].join(' '));
  }

  rl.close();
});

This code assumes that the input matrix is square (i.e., the number of rows equals the number of columns). It also assumes that the input matrix does not contain any non-integer values.

Please note that this code does not handle the case where the number of rows or columns is not a perfect square. In such a case, the last remaining row or column will be left in its original order, because the remaining rows or columns are already in their rotated state.