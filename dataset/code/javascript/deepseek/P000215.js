const readline = require('readline');

const rl = readline.createInterface({
    input: process.stdin,
    output: process.stdout
});

let [N, K] = rl.question('').split(' ').map(item => parseInt(item, 10));

const nums = rl.question('').split(' ').map(item => parseInt(item, 10));

function maxAverage(nums, K) {
    let windowSum = nums.slice(0, K).reduce((a, b) => a + b, 0);
    let maxSum = windowSum;

    for (let i = K; i < nums.length; i++) {
        windowSum = windowSum - nums[i - K] + nums[i];
        maxSum = Math.max(maxSum, windowSum);
    }

    return maxSum / K;
}

console.log(maxAverage(nums, K));