const readline = require('readline');

const rl = readline.createInterface({
  input: process.stdin,
  output: process.stdout
});

let cases = [];

rl.on('line', function(line) {
  cases.push(line);
  if (cases.length == 2) {
    rl.close();
  }
});

rl.on('close', function() {
  solve(cases[0], cases[1]);
});

function solve(N, K, arr = []) {
  arr.push(...new Array(N).fill(0));

  let min = Number.MAX_SAFE_INTEGER,
      max = Number.MIN_SAFE_INTEGER,
      sum = 0,
      tmp = 0,
      d = 0,
      i, j, p;

  for (i = 0; i < N - 1; i++) {
    for (j = i + 1; j < N; j++) {
      d = arr[j] - arr[i];
      sum += d;
      if (d > max) {
        max = d;
      }
      if (d < min) {
        min = d;
     
      }
    }
  }

  console.log(max - min);
}