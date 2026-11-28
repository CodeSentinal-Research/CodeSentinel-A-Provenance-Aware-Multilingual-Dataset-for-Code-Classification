Here is the JavaScript code that solves the given problem:

let readline = require('readline');

const rl = readline.createInterface({
  input: process.stdin,
  output: process.stdout
});

rl.question('Enter number of denominations: ', (n) => {
  const denominations = [];
  rl.question('Enter coin denominations: ', (denominationStr) => {
    denominations = denominationStr.split(' ').map(Number);
    denominations.sort((a, b) => b - a);
    rl.question('Enter target amount: ', (amount) => {
      let count = new Array(amount + 1).fill(0);
      count[0] = 1;
      denominations.forEach(coin => {
        for (let i = coin; i <= amount; i++) {
          count[i] += count[i - coin];
        }
      });
      console.log(count[amount]);
      rl.close();
    });
  });
});

This script reads the number of denominations and then the coin denominations from the user. It sorts the denominations in descending order and then calculates the total number of ways to form the target amount using unlimited copies of each coin. It uses dynamic programming to store the results of each subproblem and uses them to calculate the final result.