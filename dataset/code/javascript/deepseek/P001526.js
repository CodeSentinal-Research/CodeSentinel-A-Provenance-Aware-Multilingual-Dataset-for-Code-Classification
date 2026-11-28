Here is the JavaScript code for the problem:

const readline = require('readline');

const rl = readline.createInterface({
  input: process.stdin,
  output: process.stdout
});

let arr = [];

rl.question('Enter length of array and target: ', (length) => {
  rl.question('Enter elements of array: ', (input) => {
    arr = input.split(' ').map(Number);
    let target = Number(length);
    console.log(minSubarray(arr, target));
    rl.close();
  });
});

function minSubarray(arr, target) {
  let minLen = Infinity;
  let left = 0;
  let sum = 0;
  for (let right = 0; right < arr.length; right++) {
    sum += arr[right];
    while (sum >= target) {
      minLen = Math.min(minLen, right - left + 1);
      sum -= arr[left++];
    }
  }
  return minLen === Infinity ? 0 : minLen;
}
This program uses two pointers (left and right) to traverse the array. The sum of the subarray from left to right is calculated. If the sum is greater than or equal to the target, the size of the subarray is updated if necessary and the left pointer is moved to the right. If the sum is less than the target, the right pointer is moved to the right. The process continues until the right pointer reaches the end of the array.