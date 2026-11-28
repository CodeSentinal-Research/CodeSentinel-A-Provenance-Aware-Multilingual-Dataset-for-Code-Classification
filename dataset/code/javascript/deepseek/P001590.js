Here is the JavaScript code for the problem:

let input = require('fs').readFileSync('/dev/stdin', 'utf8');
let lines = input.split('\n');
let N = parseInt(lines[0].split(' ')[0]);
let budget = parseInt(lines[0].split(' ')[1]);
let chargeTimes = lines[1].split(' ').map(Number);
let runningCosts = lines[2].split(' ').map(Number);

let dp = new Array(budget + 1).fill(-1);
dp[0] = 0;

for(let i = 0; i < N; i++) {
    for(let j = chargeTimes[i]; j <= budget; j++) {
        dp[j] = Math.max(dp[j], dp[j - chargeTimes[i]] + runningCosts[i]);
    }
}

console.log(dp[budget]);

This code uses dynamic programming to solve the problem. It first prepares a 1D array `dp` to store the maximum number of robots that can be operated under each budget. `dp[j]` represents the maximum number of robots that can be operated with a budget `j`.

The outer loop iterates over all possible budgets from 0 to the total budget. For each budget, the inner loop iterates over all charge times from the charge time of the current robot to the total budget. If the current charge time is less than or equal to the budget, it updates the maximum number of robots that can be operated for this budget by taking the maximum between the current maximum and the maximum number of robots that can be operated without exceeding the budget with the current charge time.

Finally, it prints the maximum number of robots that can be operated under the total budget.