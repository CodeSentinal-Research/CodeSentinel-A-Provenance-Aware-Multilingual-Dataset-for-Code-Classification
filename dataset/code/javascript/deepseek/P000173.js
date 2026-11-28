Here is the JavaScript code for the problem:

let input = require('fs').readFileSync('/dev/stdin', 'utf8');
let N = parseInt(input.split('\n')[0]);
let arr = input.split('\n')[1].split(' ').map(Number);
let maxDiff = -1;
let minVal = arr[0];
for (let i = 1; i < N; i++) {
  if (arr[i] - minVal > maxDiff) {
    maxDiff = arr[i] - minVal;
  }
  if (arr[i] < minVal) {
    minVal = arr[i];
  }
}
console.log(maxDiff);

This code reads the input as a string, splits it into two parts, and then converts the second part into an array of numbers. It finds the minimum value and then for each number in the array, it checks if the difference between the current number and the minimum value is greater than the current maximum difference. If it is, it updates the maximum difference. If it is not greater than the current maximum difference, but the current number is less than the minimum value, it updates the minimum value. At the end of the code, it prints the maximum difference.