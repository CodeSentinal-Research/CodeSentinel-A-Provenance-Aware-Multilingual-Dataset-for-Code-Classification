Here is the JavaScript code for finding the length of the longest common subsequence:

const readline = require('readline');

const rl = readline.createInterface({
  input: process.stdin,
  output: process.stdout
});

let input1 = "";
let input2 = "";

rl.question('Enter the first string: ', (answer) => {
  input1 = answer;
  rl.question('Enter the second string: ', (answer) => {
    input2 = answer;
    console.log('Length of the longest common subsequence is: ' + longestCommonSubsequence(input1, input2));
    rl.close();
  });
});

function longestCommonSubsequence(s1, s2) {
  const m = s1.length;
  const n = s2.length;
  const dp = new Array(m + 1).fill(0).map(() => new Array(n + 1).fill(0));

  for (let i = 1; i <= m; i++) {
    for (let j = 1; j <= n; j++) {
      if (s1[i - 1] === s2[j - 1]) {
        dp[i][j] = dp[i - 1][j - 1] + 1;
      } else {
        dp[i][j] = Math.max(dp[i - 1][j], dp[i][j - 1]);
      }
    }
  }

  return dp[m][n];
}
This code uses a dynamic programming approach to solve the longest common subsequence problem. It creates a matrix where each cell dp[i][j] represents the length of the longest common subsequence of the first i characters of s1 and the first j characters of s2. The base case is when either of the strings is empty, it returns 0. For the remaining case, if the characters at the current position in both strings match, we increase the length by 1, otherwise, we pick the maximum value from the previous row and column.