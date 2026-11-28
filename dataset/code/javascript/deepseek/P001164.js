Here is the JavaScript code that solves the problem.

let input = require('fs').readFileSync('/dev/stdin', 'utf8');
let lines = input.split('\n');
let A = lines[0];
let B = lines[1];

let dp = new Array(B.length + 1);
for(let i = 0; i <= B.length; i++) {
    dp[i] = new Array(A.length + 1).fill(-Infinity);
}

let sumA = 0, sumB = 0, sumEqual = 0;
for(let i = 0; i < A.length; i++) {
    sumA += A.charCodeAt(i);
}
for(let i = 0; i < B.length; i++) {
    sumB += B.charCodeAt(i);
}
for(let i = 0; i < A.length; i++) {
    for(let j = 0; j < B.length; j++) {
        if(A.charAt(i) == B.charAt(j)) {
            dp[j + 1][i + 1] = dp[j][i] + (A.charAt(i) == B.charAt(j) ? 0 : A.charCodeAt(i) + B.charCodeAt(j));
        } else {
            dp[j + 1][i + 1] = Math.max(dp[j + 1][i + 1], dp[j][i + 1], dp[j + 1][i]);
        }
    }
}

console.log(Math.abs(sumA + sumB - 2 * dp[B.length][A.length]));

This code first calculates the sum of ASCII values of characters in strings A and B. It then fills up a 2D DP table with the maximum sum that can be achieved by deleting characters from strings A and B. The result is the minimum sum of ASCII values of characters that must be deleted from strings A and B to make them equal.