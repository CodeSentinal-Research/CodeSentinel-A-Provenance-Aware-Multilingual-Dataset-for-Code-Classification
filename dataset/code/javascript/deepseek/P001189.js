function maxProfit(prices, k) {
  const dp = Array(k + 1).fill(0).map(() => Array(prices.length + 1).fill(0));
  
  for(let i = 1; i <= k; i++) {
    let max = -prices[0];
    for(let j = 1; j <= prices.length; j++) {
      dp[i][j] = Math.max(dp[i][j - 1], max + prices[j]);
      max = Math.max(max, dp[i - 1][j] - prices[j]);
    }
  }
  
  return dp[k][prices.length];
}

let n = readline();
let k = readline();
let prices = readline().split(' ').map(Number);
console.log(maxProfit(prices, k));