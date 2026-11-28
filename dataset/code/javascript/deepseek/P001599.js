const readline = require('readline');

const rl = readline.createInterface({
  input: process.stdin,
  output: process.stdout
});

let input = [];

rl.on('line', (line) => {
  input.push(line.split(' ').map(Number));
})
.on('close', () => {
  const [N, K] = input.pop();
  const arr = input.flat();
  const [Q] = input.pop();
  const ranges = input.map(x => [x[0], x[1]]);

  const result = arr.slice(0, N).filter((num, i) => {
    return (i + 1) % K === 0;
  }).reduce((acc, num) => acc + 1, 0);

  for (let i = 0; i < Q; i++) {
    const [L, R] = ranges[i];
    const multiples = arr.slice(L - 1, R).filter((num, i) => {
      return (i + 1) % K === 0;
    }).reduce((acc, num) => acc + 1, 0);
    console.log(multiples);
  }

  rl.close();
})

This code reads a list of integers and multiple ranges from the standard input. For each range, it counts how many numbers in the range are multiples of K and prints the count to the standard output. It assumes that the index of each number is 1-based (i.e., the first number is 1, not 0).