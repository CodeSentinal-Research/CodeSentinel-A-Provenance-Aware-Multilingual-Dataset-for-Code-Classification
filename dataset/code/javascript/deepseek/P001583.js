Here is the JavaScript code to solve the problem:

const readline = require('readline');

const rl = readline.createInterface({
    input: process.stdin,
    output: process.stdout
});

let inputs = [];

rl.on('line', function(line) {
    inputs = line.split(' ').map(Number);
    rl.close();
}).on('close', function() {
    console.log(`${countSubarrays(inputs[0], inputs[1])}`);
    process.exit();
});

function countSubarrays(n, k) {
    let count = 0;
    let distinctCount = 0;
    let left = 0;
    let right = 0;
    let frequency = new Map();

    while (right < n) {
        if (frequency.get(inputs[right]) === undefined) {
            distinctCount++;
        }
        frequency.set(inputs[right], (frequency.get(inputs[right]) || 0) + 1);

        while (distinctCount > k) {
            if (frequency.get(inputs[left]) === 1) {
                frequency.delete(inputs[left]);
                distinctCount--;
            } else {
                frequency.set(inputs[left], frequency.get(inputs[left]) - 1);
            }
            left++;
        }

        count += distinctCount;
        right++;
    }

    return count;
}
This code reads the inputs from the standard input and outputs the count of subarrays containing at most k distinct integers. The function `countSubarrays` is the main function that calculates the count. It maintains two pointers `left` and `right` and uses a map to store the frequency of integers in the subarray. It iterates over the array, updating the count and distinct count when necessary.