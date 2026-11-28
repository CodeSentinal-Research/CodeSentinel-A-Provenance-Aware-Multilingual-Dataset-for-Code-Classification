Here is the JavaScript solution:

const readline = require('readline');

const rl = readline.createInterface({
  input: process.stdin,
  output: process.stdout
});

let inputs = [];

rl.on('line', (line) => {
  inputs.push(line);
}).on('close', () => {
  const N = parseInt(inputs[0].split(' ')[0]);
  const M = parseInt(inputs[0].split(' ')[1]);
  const K = parseInt(inputs[0].split(' ')[2]);

  const matrix = inputs.slice(1).map(row => row.split(' ').map(Number));
  
  const prefixSum = Array.from({length: N + 1}, () => 0);
  const sortedSums = Array.from({length: N * M + 1}, () => 0);

  inputs.slice(1).forEach((row, i) => {
    row.split(' ').forEach((num, j) => {
      prefixSum[i + 1] += prefixSum[i] + num;
    });
    sortedSums[prefixSum[i + 1]] = Math.max(sortedSums[prefixSum[i + 1]], prefixSum[i + 1]);
  });

  for (let i = 1; i <= prefixSum.length - 2; i++) {
    sortedSums[i] = Math.max(sortedSums[i], sortedSums[i - 1]);
  }

  function binarySearch(arr, target) {
    let low = 0;
    let high = arr.length - 1;

    while (low < high) {
      const mid = Math.floor((low + high) / 2);

      if (arr[mid] < target) {
        low = mid + 1;
      } else {
        high = mid;
      }
    }
    return low;
  }

  let maxSum = 0;
  inputs.slice(1).forEach((row, i) => {
    row.split(' ').forEach((num, j) => {
      const target = prefixSum[i] + num - K;
      const index = binarySearch(sortedSums, target);

      if (index !== sortedSums.length) {
        maxSum = Math.max(maxSum, sortedSums[index]);
      }
    });
  });

  console.log(maxSum);

  rl.close();
});

This JavaScript code first reads the inputs for N, M, and K from the standard input. Then it creates a 2D array (matrix) with the given inputs. It calculates the prefix sum array, which is a 1D array that stores the sum of each prefix sum. It also creates another 1D array (sortedSums) to keep track of the maximum sum of each prefix sum that is less than or equal to the current prefix sum. Finally, it uses a binary search algorithm to find the maximum sum of a submatrix that does not exceed K.