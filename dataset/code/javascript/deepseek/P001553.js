Here is a JavaScript solution using a sliding window approach:

const readline = require('readline');

const rl = readline.createInterface({
    input: process.stdin,
    output: process.stdout
});

let inputs = [];

rl.on('line', function(line) {
    inputs.push(line);
    if (inputs.length === 2) rl.close();
}).on('close', function() {
    processInputs(inputs);
});

function processInputs(inputs) {
    let [N, K] = inputs[0].split(' ').map(Number);
    let nums = inputs[1].split(' ').map(Number);

    let left = 0;
    let right = 0;
    let distinctCount = 0;
    let count = new Map();

    while (right < N) {
        if (!count.has(nums[right])) {
            distinctCount++;
            count.set(nums[right], true);
        } else {
            count.set(nums[right], false);
        }

        while (distinctCount > K) {
            if (!count.get(nums[left])) {
                distinctCount--;
            }
            count.set(nums[left], true);
            left++;
        }

        right++;
    }

    console.log(right - left + 1);
}

This code reads inputs from the standard input in two parts. The first part is a line containing two space-separated integers, N and K. The second part is a line containing N space-separated integers, representing the array of integers. The inputs are processed and the longest subarray with at most K distinct integers is printed to the standard output.