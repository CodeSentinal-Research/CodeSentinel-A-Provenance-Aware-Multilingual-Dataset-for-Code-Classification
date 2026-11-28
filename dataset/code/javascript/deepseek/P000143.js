const readline = require('readline');

const rl = readline.createInterface({
  input: process.stdin,
  output: process.stdout
});

let rows, cols;

rl.question('Enter the number of rows: ', (answer1) => {
  rows = parseInt(answer1);

  rl.question('Enter the number of columns: ', (answer2) => {
    cols = parseInt(answer2);

    if (rows > 50 || cols > 50 || rows < 1 || cols < 1) {
      console.log('Invalid input. Please enter a number between 1 and 50.');
      rl.close();
    } else {
      let matrix = [];

      for (let i = 0; i < rows; i++) {
        matrix[i] = [];
        for (let j = 0; j < cols; j++) {
          matrix[i][j] = rl.question(`Enter element at position [${i+1}, ${j+1}]: `);
        }
      }

      console.log('Original Matrix:');
      console.log(matrix);

      let transposedMatrix = [];

      for (let i = 0; i < cols; i++) {
        transposedMatrix[i] = [];
        for (let j = 0; j < rows; j++) {
          transposedMatrix[i][j] = matrix[j][i];
        }
      }

      console.log('Transposed Matrix:');
      console.log(transposedMatrix);
      rl.close();
    }
  });
});