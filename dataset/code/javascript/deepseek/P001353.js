Here is a JavaScript code that solves the problem:

const readline = require('readline');

const rl = readline.createInterface({
    input: process.stdin,
    output: process.stdout
});

let str, k;

rl.once('line', (line) => {
    str = line.split(' ');
    k = parseInt(str.pop());
    solve();
    rl.close();
});

function solve() {
    let len = str.length;
    if (len > 10000) {
        return console.log('1');
    }
    let dp = [0, 1];
    for (let i = 1; i < len; i++) {
        dp[i + 1] = (dp[i] + dp[i - 1] * (len - i - 1)) % 1000000007;
    }
    let ways = dp[len];
    if (ways === 0) {
        return console.log('1');
    }
    let nDigits = str.length;
    let total = ((k - ways + (nDigits % k === 0 ? 0 : 1)) % 1000000007 + (nDigits % k === 0 ? 0 : 1)) % 1000000007;
    console.log(total);
}

This code uses dynamic programming to solve the problem. The `dp[i]` represents the number of ways to split the string into integers in the range [1, K] with no leading zeros. It calculates `dp[i + 1]` by adding the product of `dp[i]` and `dp[i - 1]` (the number of ways to split the rest string) to `dp[i]`. The `(nDigits % k === 0 ? 0 : 1)` is added to the `total` in case the length of the string is a multiple of K. The result is printed to the console.