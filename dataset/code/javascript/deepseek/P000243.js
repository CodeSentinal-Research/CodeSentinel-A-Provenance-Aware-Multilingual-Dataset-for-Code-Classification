Here's the code in JavaScript:

let readline = require('readline');

const rl = readline.createInterface({
  input: process.stdin,
  output: process.stdout
});

rl.question('Enter the number of rows: ', (rows) => {
  rl.question('Enter the number of columns: ', (cols) => {
    rl.question('Enter the target: ', (target) => {
      let matrix = [];
      for(let i = 0; i < rows; i++) {
        matrix.push(readline.question('Enter row ' + (i+1) + ' elements: ').split(' ').map(Number));
      }
      let row = 0;
      let col = cols - 1;
      while(row < rows && col >= 0) {
        if(matrix[row][col] === target) {
          console.log('Found');
          return;
        } else if(matrix[row][col] > target) {
          col--;
        } else {
          row++;
        }
      }
      console.log('Not Found');
      rl.close();
    });
  });
});

This code reads the number of rows, columns, and target from the standard input and then builds a matrix from the input. It then searches for the target in the matrix, printing "Found" or "Not Found" to the standard output.

Please note that the solution assumes that the matrix is strictly sorted, meaning that all values in the matrix are strictly increasing. If the matrix is not sorted, you would need to sort it before searching for the target. Also, the code does not handle the case when the target is not found in the matrix.