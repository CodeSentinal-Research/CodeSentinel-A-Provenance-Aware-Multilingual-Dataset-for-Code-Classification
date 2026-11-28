const readline = require('readline');

const rl = readline.createInterface({
  input: process.stdin,
  output: process.stdout
});

let testCases = process.env.TESTCASES ? process.env.TESTCASES.split(' ').map(Number) : [0, 0];
let N = testCases[0];
let arr = [];
let pairs = 0;

rl.on('line', function(line) {
  N = Number(line);
  arr = process.env.ARRAY ? process.env.ARRAY.split(' ').map(Number) : [0, 0, 0, 0];
  pairs = 0;

  for (let i = 0; i < N; i++) {
    for (let j = i + 1; j <= N; j++) {
      if (arr[i] ^ arr[j] === arr[i]) {
        pairs++;
      }
    }
  }

  console.log(pairs);
});