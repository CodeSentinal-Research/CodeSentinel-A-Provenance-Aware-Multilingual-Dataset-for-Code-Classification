Here is the JavaScript code:

const readline = require('readline');

const rl = readline.createInterface({
  input: process.stdin,
  output: process.stdout
});

rl.question('Enter N and K separated by space: ', (NK) => {
  const [N, K] = NK.split(' ');
  const arr = rl.question('Enter N integers separated by space: ').split(' ').map(Number);
  const zeroCount = (arr.slice(0, K - 1).includes(0) ? 0 : 1) + arr.slice(K - 1).filter(a => a === 0).reduce((count, a) => count + a, 0);
  console.log(zeroCount);
  rl.close();
});

This program uses the `readline` module to handle the input from the command line. The first line of input is read, and the second line is split into an array of integers. The count of zeroes is then calculated using the `filter` method to count the number of zeroes in the subarray. The `reduce` method is used to add up all the zeroes.