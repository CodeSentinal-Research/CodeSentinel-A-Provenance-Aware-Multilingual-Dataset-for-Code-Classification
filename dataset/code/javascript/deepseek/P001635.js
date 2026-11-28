const readline = require('readline');

const rl = readline.createInterface({
  input: process.stdin,
  output: process.stdout
});

let inputs = [];

rl.on('line', function(line) {
  inputs.push(line.split(' ').map(Number));
}).on('close', function() {
  const matrix = inputs[0];
  const rows = inputs[1];
  const cols = inputs[2];

  const count = matrix.reduce((acc, curr, idx) => {
    if (idx % rows === 0 && idx !== 0) {
      return acc + 1;
    }
    return acc;
  }, 0);

  console.log(count);

  rl.close();
});