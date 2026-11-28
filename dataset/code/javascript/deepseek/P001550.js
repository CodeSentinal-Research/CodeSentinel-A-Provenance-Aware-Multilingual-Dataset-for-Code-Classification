let readline = require('readline');

const rl = readline.createInterface({
  input: process.stdin,
  output: process.stdout
});

rl.question('Please enter the size of the array (N) and window size (K): ', (N, K) => {
  rl.question('Please enter the array elements: ', (elements) => {
    const arr = elements.split(' ').map(Number);

    let sum = 0;
    for (let i = 0; i < arr.length - K + 1; i++) {
      const window = arr.slice(i, i + K);
      sum += Math.abs(window[0] - window[window.length - 1]);
    }

    console.log(sum);
    rl.close();
  });
});
This JavaScript program reads an array of integers and a window size from the user. It then calculates the sum of absolute differences between consecutive elements in every contiguous subarray of size K. The differences are calculated by subtracting the last element from the first element in each subarray, and taking the absolute value of the difference. The sum of these differences is added to a running total. This process is repeated for all subarrays of size K, and the final sum is printed out.