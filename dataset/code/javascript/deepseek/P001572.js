Here is the JavaScript code to solve the problem:

let readline = require('readline');

let input = [];

const rl = readline.createInterface({
  input: process.stdin,
  output: process.stdout
});

rl.on('line', function(line) {
    input = line.split(' ');
});

rl.on('close', function() {
    const N = parseInt(input[0]);
    const K = parseInt(input[1]);
    const nums = input.slice(2).map(Number);

    let count = 0;

    for (let i = 0; i < N; i++) {
        let sum = nums[i];
        if (i < K - 1) {
            sum += nums[i + 1];
        }
        if (sum % 2 === 0) {
            count++;
        }
        for (let j = i + 1; j < N; j++) {
            sum -= nums[j - 1];
            if (j < K - 1) {
                sum += nums[j + 1];
            }
            if (sum % 2 === 0) {
                count++;
            }
        }
    }

    console.log(count);
});

This script first reads the line of numbers. It then iterates over the numbers to find the subarrays that sum to an even number. It counts the total number of even sums. The sum of a subarray is either the current number or the current number plus the next number, depending on whether the current number is the first or last in the subarray.