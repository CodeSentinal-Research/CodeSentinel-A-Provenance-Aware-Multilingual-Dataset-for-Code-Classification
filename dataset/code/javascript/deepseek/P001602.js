const readline = require('readline');

const rl = readline.createInterface({
  input: process.stdin,
  output: process.stdout
});

let n;
rl.question('Enter the number of elements: ', (num) => {
  n = parseInt(num);
  const arr = [];
  rl.question('Enter the elements: ', (input) => {
    arr = input.split(' ').map(Number);
    console.log(maxAbsolutePrefixSum(arr));
    rl.close();
  });
});

function maxAbsolutePrefixSum(arr) {
  if (arr.length === 0) return 0;

  let maxSum = arr[0];
  let minSum = arr[0];
  let max = arr[0];

  for (let i = 1; i < arr.length; i++) {
    if (arr[i] < 0) {
      let temp = maxSum;
      maxSum = minSum;
      minSum = temp;
    }

    maxSum = Math.max(arr[i], maxSum + arr[i]);
    minSum = Math.min(arr[i], minSum + arr[i]);

    max = Math.max(max, maxSum);
  }

  return max;
}