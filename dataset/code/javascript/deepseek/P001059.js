Here is a simple JavaScript code for the problem:

const readline = require('readline');

const rl = readline.createInterface({
  input: process.stdin,
  output: process.stdout
});

rl.question('Enter the number of elements: ', (n) => {
  rl.question('Enter the elements: ', (elements) => {
    let arr = elements.split(' ').map(Number);

    const findMinimumDeviation = (arr) => {
      let maxDiff = Number.MAX_SAFE_INTEGER;
      const dfs = (index, max, min) => {
        if (index === arr.length) {
          maxDiff = Math.min(maxDiff, max - min);
          return;
        }
        dfs(index + 1, Math.max(max, arr[index]), Math.min(min, arr[index]));
        dfs(index + 1, max, min);
      };
      dfs(0, 0, Number.MAX_SAFE_INTEGER);
      return maxDiff;
    };
    console.log(findMinimumDeviation(arr));
    rl.close();
  });
});

In this code, we are first asking for the number of elements and the elements itself. After getting the input, we then call the `findMinimumDeviation` function which will return the minimum possible deviation.

The `findMinimumDeviation` function uses a depth-first search (DFS) to explore all possible configurations of the array, and then find the minimum difference between the maximum and minimum values found.

Please note, this code assumes that the input numbers are always integers and that there's always at least one odd number and one even number in the array.