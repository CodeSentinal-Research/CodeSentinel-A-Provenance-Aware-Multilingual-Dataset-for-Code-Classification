Here is the JavaScript code to solve the problem. This code uses the dynamic programming approach to find the longest increasing subsequences.

let readline = require('readline');

const rl = readline.createInterface({
    input: process.stdin,
    output: process.stdout
});

let testCases = [];

rl.once('line', line => {
    let num = parseInt(line);
    for(let i = 0; i < num; i++) {
        rl.once('line', line => {
            let input = line.split(' ').map(Number);
            testCases.push(input);
            if(i < num - 1) rl.once('line', line => {});
        });
    });

rl.close();

function solve(n, a) {
    let dp = Array(n).fill(1);
    let pos = Array(n).fill(0);

    for (let i = 1; i < n; i++) {
        for (let j = 0; j < i; j++) {
            if (a[i] > a[j]) {
                if (dp[i] < dp[j] + 1) {
                    dp[i] = dp[j] + 1;
                    pos[i] = j;
                }
            }
        }
    }

    let longestLength = Math.max(...dp);
    let longestSubseq = [];

    for (let i = dp.indexOf(longestLength); i >= 0; i = pos[i]) {
        longestSubseq.unshift(a[i]);
        longestLength--;
    }

    return longestSubseq;
}

let count = 0;

for(let i = 0; i < testCases.length; i++) {
    console.log(solve(testCases[i][0], testCases[i][1]).length);
    count++;
}

console.log(`Number of longest increasing subsequences: ${count}`);

This code reads a test case from the input, calls the `solve` function with that test case, and prints the length of the longest increasing subsequence. It repeats this process for all test cases, and then prints the total number of longest increasing subsequences.