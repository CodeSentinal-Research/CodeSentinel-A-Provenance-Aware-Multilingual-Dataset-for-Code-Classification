const readline = require('readline');

const rl = readline.createInterface({
  input: process.stdin,
  output: process.stdout
});

let N, Q;
rl.once('line', (line) => {
  [N, ...inputs] = line.split(' ');
  N = Number(N);
  Q = Number(inputs[inputs.length - 1]);
});

rl.once('line', (line) => {
  const arr = line.split(' ').map(Number);

  for (let i = 0; i < Q; i++) {
    const query = Number(rl.readline());
    if (arr.includes(query)) {
      console.log('Found');
    } else {
      console.log('Not Found');
    }
  }

  rl.close();
});