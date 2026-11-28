Here is a simple JavaScript code to solve the problem:

function maxSum(arr, k) {
    let windowSum = arr.slice(0, k).reduce((a, b) => a + b, 0);
    let maxSum = windowSum;

    for (let i = k; i < arr.length; i++) {
        windowSum = windowSum - arr[i - k] + arr[i];
        maxSum = Math.max(maxSum, windowSum);
    }

    return maxSum;
}

function solveProblem() {
    let [N, K] = readline().split(' ').map(Number);
    let arr = readline().split(' ').map(Number);
    console.log(maxSum(arr, K));
}

In this code, we define a function `maxSum` that computes the maximum sum of a subarray of size K using a sliding window approach. It takes as input an array and an integer K, and returns the maximum sum of a subarray of size K.

The `solveProblem` function reads the input and calls the `maxSum` function with the appropriate arguments.

Please note that `readline` is a placeholder for the actual implementation of a function to read input from the standard input, such as `readline()` in Node.js. The actual implementation depends on the environment where this code is running.

This code assumes that the input is a single line containing two integers, followed by a space-separated list of integers.