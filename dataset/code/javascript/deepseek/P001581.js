let readline = require('readline');

const rl = readline.createInterface({
  input: process.stdin,
  output: process.stdout
});

let cases = [];
rl.once('line', (line) => {
  cases.push(line.split(' '));
  rl.once('line', (line) => {
    console.log(maxLength(cases[0][0], cases[0][1], cases.slice(1)));
  });
});

function maxLength(n, k, arr) {
  let negatives = arr.filter(num => num < 0).map((num, index) => [num, index]).sort((a, b) => a[1] - b[1]);
  let left = 0;
  let right = 0;
  let result = 0;

  while (right < negatives.length) {
    if (negatives[right][1] - negatives[left][1] > k) {
      left++;
    } else {
      result = Math.max(result, right - left + 1);
      right++;
   
      if (right === negatives.length) {
        left = right;
      }
    }
  }

  return result;
}

This JavaScript code reads a list of integers and a maximum negative number count as input, and prints the length of the longest subarray of negative numbers that do not exceed the maximum negative number count. The code uses two pointers and a sliding window approach to find the longest subarray.