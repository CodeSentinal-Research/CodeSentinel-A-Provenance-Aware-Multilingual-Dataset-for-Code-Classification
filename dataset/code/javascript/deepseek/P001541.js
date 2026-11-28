const readline = require('readline');

const rl = readline.createInterface({
  input: process.stdin,
  output: process.stdout
});

let inputs = [];

rl.on('line', function(line) {
  inputs = line.split(' ');
  inputs = inputs.map(Number);
  
  let N = inputs[0];
  let K = inputs[1];
  let A = inputs.slice(2);
  
  console.log(maxSum(A, K));
  
  rl.close();
});

function maxSum(A, K) {
  let windowSum = A.slice(0, K).reduce((a, b) => a + b, 0);
  let maxSum = windowSum;

  for(let i = K; i < A.length; i++) {
    windowSum = windowSum - A[i - K] + A[i];
    maxSum = Math.max(maxSum, windowSum);
  }

  return maxSum;
}