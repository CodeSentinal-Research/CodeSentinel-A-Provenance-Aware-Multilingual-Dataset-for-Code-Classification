Here is the JavaScript code:

const readline = require('readline');

const rl = readline.createInterface({
  input: process.stdin,
  output: process.stdout
});

rl.question('Enter the size of the array: ', (n) => {
  rl.question('Enter the target: ', (target) => {
    const arr = rl.question('Enter the elements of the array: ').split(' ').map(Number);
    arr.sort((a, b) => a - b);
    console.log(findFloor(arr, target));
    rl.close();
  });
});

function findFloor(arr, target) {
  let left = 0;
  let right = arr.length - 1;
  while (left <= right) {
    const mid = Math.floor((left + right) / 2);
    if (arr[mid] === target) return arr[mid];
    else if (arr[mid] < target) left = mid + 1;
    else right = mid - 1;
  }
  return -1;
}

This program uses binary search to find the floor of a target in a sorted array. The `findFloor` function takes a sorted array and a target number as input. It returns the floor of the target in the array, or -1 if the target is not found.

The program reads the size of the array and the target from the user, then reads the elements of the array. The array is sorted in ascending order before the binary search, and the floor of the target is returned.