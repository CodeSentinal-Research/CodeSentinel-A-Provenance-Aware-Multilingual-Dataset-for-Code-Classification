let readline = require('readline');

const rl = readline.createInterface({
    input: process.stdin,
    output: process.stdout
});

let arr = [];

rl.on('line', function(line) {
    arr = line.split(' ').map(Number);
    findMaxSum(arr);
})

function findMaxSum(arr) {
    let maxSum = -Infinity, currentSum = 0;
    for(let i = 0; i < arr.length; i++) {
        currentSum += arr[i];
        if(maxSum < currentSum) maxSum = currentSum;
        if(currentSum < 0) currentSum = 0;
    }
    console.log(maxSum);
}
In this code, we use the readline module to handle the input from the standard input. We create an array and read the input line by line, splitting the line into an array of numbers. We call the `findMaxSum` function with this array as the argument. The `findMaxSum` function iterates through the array, adding each number to the `currentSum`. If `currentSum` is greater than `maxSum`, we update `maxSum`. If `currentSum` is less than zero, we reset `currentSum` to zero. The maximum `maxSum` is the maximum sum of any contiguous subarray.