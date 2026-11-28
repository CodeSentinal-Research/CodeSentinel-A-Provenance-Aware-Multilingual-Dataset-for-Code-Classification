Here is the JavaScript code to solve the problem:

let readline = require('readline');

let rl = readline.createInterface({
    input: process.stdin,
    output: process.stdout
});

let line = '';

rl.on('line', function(l) {
    line += l;
});

rl.on('close', function() {
    let [N, M] = line.split(' ').map(Number);
    let arr = rl.read().split(' ').map(Number);

    let dp = Array.from({length: N + 1}, () => new Array(M + 1).fill(0));
    let prefixSum = Array.from({length: N + 1}, () => 0);

    for(let i = 1; i <= N; i++) {
        prefixSum[i] = prefixSum[i - 1] + arr[i - 1];
    }

    for(let i = 1; i <= N; i++) {
        for(let j = 1; j <= M; j++) {
            for(let k = 1; k <= i; k++) {
                dp[i][j] = Math.max(dp[i][j], dp[k - 1][j - 1] + ((j === 1) ? 0 : dp[i - k][j - 1]) + prefixSum[i]);
            }
        }
    }

    console.log(dp[N][M]);
});

This code uses Dynamic Programming (DP) to solve the problem. The dp array stores the maximum sum for each subarray up to each index in the array. The prefixSum array stores the prefix sum of the array. The outer loop iterates over the array, the middle loop iterates over the subarray, and the inner loop iterates over the possible number of elements in the subarray. The dp[i][j] stores the maximum sum for the subarray up to the i-th element in the array and has j subarrays.