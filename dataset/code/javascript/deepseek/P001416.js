Here is the JavaScript code that solves the problem:

let input = require('fs').readFileSync('stdin', 'utf-8');
let N = Number(input.split('\n')[0]);
let arr = input.split('\n')[1].split(' ').map(Number);

let map = new Map();
let maxLen = 0;

for (let num of arr) {
  for (let i = -1; i <= 1; i++) {
    if (map.has(num + i)) {
      map.get(num + i).push(num);
    } else {
      map.set(num + i, [num]);
    }
  }

  if (map.get(num).length > maxLen) {
    maxLen = map.get(num).length;
  }
}

console.log(maxLen);

This code reads the input as a string and then splits it into N and arr. arr is then processed in a loop to find the longest harmonious subsequence length. The map is used to store the maximum length of harmonious subsequence for each number.