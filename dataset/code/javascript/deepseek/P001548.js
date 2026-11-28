Here is the JavaScript code for the problem:

let readline = require('readline');

const rl = readline.createInterface({
  input: process.stdin,
  output: process.stdout
});

let inputs = [];

rl.on('line', function(line) {
  inputs = line.split(' ');
  const N = parseInt(inputs[0]);
  const K = parseInt(inputs[1]);
  const arr = inputs.slice(2).map(num => parseInt(num));

  if (N < 1 || N > 10000) {
    rl.close();
    console.log('Invalid N. It should be between 1 and 10000.');
    return;
  }

  if (K < 1 || K > N) {
    rl.close();
    console.log('Invalid K. It should be between 1 and N.');
    return;
  }

  for (let i = 0; i < N; i++) {
    if (arr[i] < 1 || arr[i] > 20) {
      rl.close();
      console.log('Invalid array elements. They should be between 1 and 20.');
      return;
    }
  }

  console.log('Maximum product: ' + maxProductInWindow(arr, K));
});

The code takes input as an array of N positive integers and K. It then checks if N and K are within the constraints and if all elements in the array are within the constraints. If all checks are passed, it calculates and prints the maximum product among all contiguous subarrays of size K.