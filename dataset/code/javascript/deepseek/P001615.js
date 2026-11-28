const readline = require('readline');

const rl = readline.createInterface({
  input: process.stdin,
  output: process.stdout
});

rl.question('Enter N M Target: ', (N) => {
  const matrix = [];
  let target = [];

  rl.setPrompt('Enter matrix elements: ');
  rl.close();

  rl.on('line', (line) => {
    if (line.length === 0) {
      rl.close();
      processMatrix(matrix, target);
      return;
    }
    matrix.push(line.split(' ').map(Number));
  });

  function processMatrix(matrix, target) {
    let count = 0;
    for (let i = 0; i < matrix.length; i++) {
      for (let j = 0; j < matrix[i].length; j++) {
        for (let k = 0; k < matrix.length; k++) {
          for (let l = 0; l < matrix[k].length; l++) {
            if (matrix[i][j] + matrix[k][l] === target) {
              count++;
            }
          }
        }
      }
    }
    console.log(count);
  }
});

This JavaScript program reads the input matrix and target number from the console. It then loops through the matrix, calculating the sum of each element with the target number. If the sum is equal to the target, it increments a counter. The counter is then printed out.