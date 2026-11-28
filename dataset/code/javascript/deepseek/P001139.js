Here is the JavaScript code for the given problem:

let readline = require('readline');

const rl = readline.createInterface({
    input: process.stdin,
    output: process.stdout
});

let inputs = [];

rl.on('line', function(line) {
    inputs.push(line);
}).on('close', function() {
    const [N, W] = inputs[0].split(' ').map(Number);
    const items = inputs.slice(1).map(item => item.split(' ').map(Number));

    const dp = Array(N + 1).fill(0).map(() => Array(W + 1).fill(0));

    for(let i=1; i<=N; i++) {
        const [weight, value] = items[i-1];
        for(let j=1; j<=W; j++) {
            if(weight > j) {
                dp[i][j] = Math.max(dp[i-1][j], dp[i-1][j-weight] + value);
            } else {
                dp[i][j] = Math.max(dp[i-1][j], dp[i-1][j-weight] + value, dp[i-1][j-weight] + weight);
            }
        }
    }

    console.log(dp[N][W]);

    rl.close();
});
This script first reads the number of items and the capacity of the knapsack from the standard input. Then it reads the weights and values of each item and uses a dynamic programming approach to find the maximum value that can be obtained within the given capacity. The dynamic programming table dp is used to store the maximum obtainable value for each possible weight up to the capacity.