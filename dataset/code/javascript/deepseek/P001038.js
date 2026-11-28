Here is the JavaScript code to solve the problem:

let readline = require('readline');

const rl = readline.createInterface({
    input: process.stdin,
    output: process.stdout
});

let cases = parseInt(rl.readline()); // read number of test cases

rl.once('line', () => {
    let [N, K] = rl.line().split(' ').map(Number);
    let capital = JSON.parse(rl.line());
    let profit = JSON.parse(rl.line());

    let dp = new Array(K + 1).fill(0);
    dp[0] = capital[0];

    for (let i = 1; i < N; i++) {
        for (let j = K; j >= capital[i]; j--) {
            dp[j] = Math.max(dp[j], dp[j - capital[i]] + profit[i]);
        }
    }

    console.log(dp[K]);

    rl.close();
});

This code reads the number of test cases, and for each test case, it reads the number of projects (N) and the maximum capital (K). It then reads the capital requirements and profits of the projects. The code uses a dynamic programming approach to solve the problem. It iterates through all the projects, and for each project, it checks if it can be completed with the current capital. If it can, it updates the maximum capital by adding the profit to the current capital.