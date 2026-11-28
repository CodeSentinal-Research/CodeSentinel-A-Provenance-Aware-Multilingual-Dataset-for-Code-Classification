Here is the JavaScript code:

const readline = require('readline');

const rl = readline.createInterface({
    input: process.stdin,
    output: process.stdout
});

let [N, Difference] = rl.question('').split(' ').map(item => parseInt(item));
let arr = rl.question('').split(' ').map(item => parseInt(item));

function solve(N, Difference, arr) {
    let dp = new Array(N).fill(0).map(() => new Array(N).fill(0));
    let dp2 = new Array(N).fill(0).map(() => new Array(N).fill(0));
    for (let i = 0; i < N; i++) {
        for (let j = i + 1; j < N; j++) {
            if (arr[j] - arr[i] == Difference) {
                dp[i][j] = dp[j][i] = 2;
            }
       
            dp[i][j] = Math.max(dp[i][j], dp[i][j - 1], dp[j - 1][i]);

            dp2[i][j] = Math.max(dp2[i][j], dp2[i][j - 1], dp2[j - 1][i]);
            if (arr[j] - arr[i] == -Difference) {
                dp2[i][j] = Math.max(dp2[i][j], dp2[j][i] + 1);
            }

            if (arr[j] - arr[i] == Difference) {
                dp2[i][j] = Math.max(dp2[i][j], dp2[j][i] + 1);
            }
        }
    }

    let res = 0;
    for (let i = 0; i < N; i++) {
        for (let j = i; j < N; j++) {
            res = Math.max(res, dp[i][j]);
            res = Math.max(res, dp2[i][j]);
        }
    }

    console.log(res);
}

solve(N, Difference, arr);

This code works by using dynamic programming to solve the problem. The first two for-loops in the `solve` function build up the subsequences that are the longest with the given difference. The final loop finds the longest subsequence in the entire array.