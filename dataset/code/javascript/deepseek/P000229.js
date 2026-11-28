const readline = require('readline');

const rl = readline.createInterface({
  input: process.stdin,
  output: process.stdout
});

rl.question('Enter the number of rows and columns: ', (n) => {
  let matrix = [];
  rl.setPrompt('Enter the matrix: ');
  for (let i = 0; i < n; i++) {
    matrix[i] = rl.question('');
  }

  let maxIndex = 0;
  let maxCount = 0;
  for (let i = 0; i < n; i++) {
    let count = matrix[i].split(' ').reduce((a, b) => a + parseInt(b), 0);
    if (count > maxCount) {
      maxCount = count;
      maxIndex = i;
    }
  }

  console.log(`Row with maximum 1s: ${maxIndex + 1}`);

  rl.close();
});
This program takes in the number of rows and columns and a matrix as input. It then counts the number of 1s in each row and keeps track of the row with the maximum count. Finally, it prints the index of the row with the maximum count.