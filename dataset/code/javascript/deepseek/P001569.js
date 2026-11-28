Here is the JavaScript code for the problem:

let readline = require('readline').createInterface({
    input: process.stdin,
    output: process.stdout
});

let arr = new Array(100000).fill(0);

readline.question('', (N) => {
    readline.question('', (arrStr) => {
        arr = arrStr.split(' ').map(Number);
        console.log(maxSubArray(arr, N));
        readline.close();
    });
});

function maxSubArray(arr, N){
    let maxSum = 0, windowSum = 0;
    let start = 0, end = 0;

    while (end < N) {
        windowSum += arr[end];

        while (windowSum > N / 2) {
            windowSum -= arr[start];
            start++;
        }

        if (windowSum === N / 2) {
            maxSum = Math.max(maxSum, windowSum);
        }

        end++;
    }

    return maxSum;
}

This program reads the size of the array and the array elements from the input and prints the maximum possible sum of a contiguous subarray containing only unique elements. The `maxSubArray` function implements a sliding window approach to solve the problem. It keeps track of the sum of the elements in the window and moves the window to the right until the sum exceeds half of `N`. It then calculates the maximum sum and prints it.