Here is the JavaScript code:

const readline = require('readline');

const rl = readline.createInterface({
    input: process.stdin,
    output: process.stdout
});

let inputs = [];

rl.on('line', (line) => {
    inputs = line.split(' ');
    let N = parseInt(inputs[0]);
    let K = parseInt(inputs[1]);
    let nums = [];
    rl.on('line', (line) => {
        if (nums.length == N) {
            rl.close();
            findMaxNegatives(nums, K);
        } else {
            nums.push(parseInt(line));
        }
    });
});

function findMaxNegatives(nums, K) {
    let count = [];
    for(let i = 0; i < nums.length; i++) {
        if(nums[i] < 0) {
            count[i] = 0;
            for(let j = i; j < i + K && j < nums.length; j++) {
                if(nums[j] < 0) {
                    count[i]++;
                }
            }
        }
    }
    console.log(Math.max(...count));
}

This code firstly reads the number of numbers and window size as input, then reads each number as it is encountered. It keeps track of the maximum count of negative numbers in each window and finally logs the maximum count.