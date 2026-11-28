Here is the JavaScript code for the Dice Throw Problem:

let [D, F, S] = require('fs').readFileSync('dev/stdin', 'utf8').split(/\s+/).map(Number);

let dp = Array(D + 1).fill(0).map(() => Array(S + 1).fill(0));

dp[0][0] = 1;

for(let i = 0; i < D; i++) {
    for(let j = 0; j <= S; j++) {
        for(let k = 1; k <= F; k++) {
            dp[i + 1][j + k] += dp[i][j];
        }
    }
}

console.log(dp[D][S]);

In this code, we use a dynamic programming (DP) approach to solve the problem. We create a 3D array (dp) where dp[i][j][k] is the number of ways to get sum j with i dice and k as the current face number. The base case is dp[0][0][0] = 1 because there is only one way to get sum 0 with 0 dice and face 0.

Then, for each dice, we update dp[i + 1][j + k] += dp[i][j] because for each roll, we can either roll the current face or roll a new face, so we add the number of ways to get the remaining sum (j + k) with i - 1 dice and the current face (k).

Finally, we print the number of ways to get sum S with D dice and F faces.