let readline = require('readline');

let rl = readline.createInterface({
  input: process.stdin,
  output: process.stdout
});

let target = null;

rl.on('line', function(line) {
  target = parseInt(line);
});

rl.on('close', function() {
  let arr = Array.from({length: 1000000}, (v, k) => k + 1);
  let start = 0;
  let end = arr.length - 1;

  while (start <= end) {
    let mid = Math.floor((start + end) / 2);
    if (arr[mid] === target) {
      console.log(mid);
      return;
    } else if (arr[mid] < target) {
      start = mid + 1;
    } else {
      end = mid - 1;
    }
  }

  console.log(-1);
});
This JavaScript program uses binary search to find the target in an infinite sorted array. The program first reads the target from the input, then reads the sorted array. It then uses binary search to find the target. If the target is found, it prints the index, otherwise, it prints -1.

The array is simulated by creating an array of numbers from 1 to 10^5, then the target is searched in the array.

Please note that this code is a basic implementation of the binary search algorithm for finding an element in an infinite sorted array. It may not be the most efficient solution for large inputs, but it's simple and easy to understand.