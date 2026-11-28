const readline = require('readline');

const rl = readline.createInterface({
  input: process.stdin,
  output: process.stdout
});

let testCases;
rl.question('Enter the number of test cases: ', (nc) => {
  testCases = Number(nc);

  for (let i = 0; i < testCases; i++) {
    let arr = [];
    rl.question('Enter max length for each jump: ', (maxLengths) => {
      arr = maxLengths.split(' ').map(Number);
      console.log(minJumps(arr));
    });
 
  }

  rl.close();
});

function minJumps(arr) {
  let dp = Array(arr.length).fill(Infinity);
  dp[0] = 0;

  for (let i = 1; i < arr.length; i++) {
    for (let j = 0; j < i; j++) {
      if (i <= j + arr[j] && dp[i] > dp[j] + 1) {
        dp[i] = dp[j] + 1;
      }
    }
  }

  return dp[arr.length - 1];
}
This script takes a line as input and then uses the input to calculate the minimum number of jumps required to reach the last index. The input for each test case is a line containing the max lengths for each jump. The script also uses dynamic programming to solve the problem. The `dp[i]` represents the minimum number of jumps required to reach the `i-th` index from the start.