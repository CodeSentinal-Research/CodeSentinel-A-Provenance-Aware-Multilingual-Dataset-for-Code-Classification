let readline = require('readline');

const rl = readline.createInterface({
  input: process.stdin,
  output: process.stdout
});

rl.question('Enter the number of rows: ', (N) => {
  let matrix = [];
  rl.setPrompt('Enter the matrix row by row: ');

  for (let i = 0; i < N; i++) {
    rl.prompt();
  }

  rl.close();
});