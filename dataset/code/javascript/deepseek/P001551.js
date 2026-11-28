const readline = require('readline');

const rl = readline.createInterface({
  input: process.stdin,
  output: process.stdout
});

rl.question('Enter number of elements and target sum (N, K): ', (N) => {
  rl.question('Enter space-separated integers: ', (inputs) => {
    const arr = inputs.split(' ').map(Number);
    const K = Number(inputs.split(' ').pop());
    console.log(longestSubarray(arr, K));
    rl.close();
  });
});

function longestSubarray(arr, K) {
  let left = 0;
  let right = 0;
  let sum = 0;
  let maxLen = 0;

  while (right < arr.length) {
    sum += arr[right];

    while (sum > K) {
      sum -= arr[left];
      left++;
    }

    maxLen = Math.max(maxLen, right - left + 1);
    right++;
  }

  return maxLen;
}