let readline = require('readline');

const rl = readline.createInterface({
  input: process.stdin,
  output: process.stdout
});

let N, arr, target;

rl.on('line', (line) => {
  let parts = line.split(' ');
  N = parseInt(parts[0]);
  arr = parts[1].split(' ').map(x => parseInt(x));
  target = parseInt(parts[2]);

  let count = 0;
  arr.forEach((element) => {
    if (element === target) count++;
  });

  console.log(count);

  rl.close();
});
This code uses Node.js's `readline` module to read lines of input from stdin. It processes each line by first splitting it into a number and an array, and then counts the number of times the target element appears in the array.