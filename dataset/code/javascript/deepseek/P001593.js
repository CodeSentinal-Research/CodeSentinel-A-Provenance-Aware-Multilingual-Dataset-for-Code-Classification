Here's a simple JavaScript code that solves the problem:

const readline = require('readline');

const rl = readline.createInterface({
  input: process.stdin,
  output: process.stdout
});

let input = [];

rl.on('line', (line) => {
  input = line.split(' ');
  rl.close();
});

rl.on('close', () => {
  processInput(input);
});

function processInput(input) {
  let N = parseInt(input[0]);
  let X = parseInt(input[1]);
  let arr = input[2].split(' ').map(Number);

  let prefixSum = [0];
  for (let i = 0; i < N; i++) {
    prefixSum[i + 1] = prefixSum[i] + arr[i];
  }

  if (prefixSum[N] <= X) {
    console.log(-1);
    return;
  }

  let minPrefixLength = N;
  for (let i = N - 1; i > 0; i--) {
    if (prefixSum[i] > X) {
      minPrefixLength = Math.min(minPrefixLength, i);
      break;
    }
  }

  console.log(minPrefixLength);
}

This code reads the input from the console and processes it. It first reads the number of elements N and the target sum X. Then it reads the actual array. The `prefixSum` array is computed and then checked to see if the sum of the prefix is greater than X. If it is, the code prints -1 and terminates. If not, the code computes the minimum prefix length and prints it.

Please note that this code expects the input to be in the following format:

N X
N1 N2 ... NN

Where `N` is the number of elements in the array, `X` is the target sum, and `Ni` is the `i`th element in the array.