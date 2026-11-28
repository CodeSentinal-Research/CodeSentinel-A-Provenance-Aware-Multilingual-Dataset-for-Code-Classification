Here is the JavaScript code for the problem:

const readline = require('readline');

const rl = readline.createInterface({
  input: process.stdin,
  output: process.stdout
});

rl.question('Enter the number of elements: ', (n) => {
  rl.question('Enter the target: ', (target) => {
    const numbers = [];
    rl.question('Enter the elements: ', (input) => {
      input.split(' ').forEach((num) => numbers.push(parseInt(num)));
      const result = binarySearch(numbers, target);
      console.log(result);
      rl.close();
    });
  });
});

function binarySearch(arr, target) {
  let start = 0;
  let end = arr.length - 1;

  while (start <= end) {
    const mid = Math.floor((start + end) / 2);

    if (arr[mid] === target) {
      return mid;
    }

    if (arr[mid] < target) {
      start = mid + 1;
    } else {
      end = mid - 1;
    }
  }

  return -1;
}
This code first reads the number of elements and the target from the input. Then it reads the array of elements. Finally, it calls the binary search function and logs the result to the console.

The binary search function works by repeatedly dividing the search interval in half. If the target value is found in the middle of the interval, the function returns the index. If the target value is less than the middle value, the function continues to search in the lower half of the interval. Otherwise, it continues to search in the upper half. If the search interval is empty (i.e., the target is not found), the function returns -1.