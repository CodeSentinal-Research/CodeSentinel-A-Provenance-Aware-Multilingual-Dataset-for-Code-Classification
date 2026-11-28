Here is the JavaScript code:

const readline = require('readline');

const rl = readline.createInterface({
  input: process.stdin,
  output: process.stdout
});

rl.question('Enter number of rows (between 1 and 50): ', (rows) => {
  rl.question('Enter number of columns (between 1 and 50): ', (cols) => {
    if (rows < 1 || rows > 50 || cols < 1 || cols > 50) {
      console.log('Invalid input. Please enter numbers between 1 and 50.');
      rl.close();
      return;
    }

    const matrix = [];

    for (let i = 0; i < rows; i++) {
      matrix[i] = [];
      for (let j = 0; j < cols; j++) {
        matrix[i][j] = rl.question(`Enter element at position (${i}, ${j}): `);
      }
    }

    printMatrixZigZag(matrix, rows, cols);

    rl.close();
  });
});

function printMatrixZigZag(matrix, rows, cols) {
  for (let k = 0; k < rows + cols - 1; k++) {
    for (let i = k < rows ? 0 : k - rows + 1; i < rows && k < rows; i++) {
      for (let j = k < cols ? 0 : k - cols + 1; j < cols && k < cols; j++) {
        console.log(matrix[i][j]);
      }
    }
    console.log('');
  }
}

In this code, we first get the number of rows and columns from the user. We then get the elements of the matrix from the user. Finally, we call the `printMatrixZigZag` function to print the matrix in zigzag order.

The `printMatrixZigZag` function prints the elements of the matrix in zigzag order. It works by iterating over the indices of the matrix in a "zigzag" pattern.