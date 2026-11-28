Here is the JavaScript code for the problem:

function solve(n) {
    let dp = [0, 1, 2];
    for(let i = 3; i <= n; i++) {
        dp[i] = dp[i - 1] + dp[i - 2];
    }
    return dp[n];
}

function main() {
    const readline = require('readline');
    const rl = readline.createInterface({
        input: process.stdin,
        output: process.stdout
    });

    rl.question('Please enter the number of steps: ', (n) => {
        console.log(solve(n));
        rl.close();
    });
}

main();

This code uses a dynamic programming approach to solve the problem. The `dp` array stores the number of ways to reach each step. The `solve` function computes the `dp` array by iterating from the third step to the given number of steps and filling in the array according to the rules of the problem. The `main` function reads the number of steps from the standard input and prints the number of ways to reach the top.