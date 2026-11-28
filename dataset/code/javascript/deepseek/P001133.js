Here is the JavaScript code to solve the problem:

function minCostClimbingStairs(cost) {
  let dp = [0, 0]; //dp array to store the minimum cost to reach each step

  for(let i = 2; i <= cost.length; i++) {
    dp[i] = Math.min(dp[i-1], dp[i-2]) + cost[i-1]; //minimum cost to reach current step is the minimum cost to reach previous step plus cost of current step
  }

  return Math.min(dp[cost.length], dp[cost.length-1]); //return minimum cost to reach the top, which is the minimum cost to reach the last step and the step before the last step
}

This function starts by initializing an array `dp` with two elements, since we can either climb 1 or 2 steps at a time. It then iterates over the `cost` array, calculating the minimum cost to reach each step. At each step, it considers the minimum cost to reach the previous step and adds the cost of the current step. Finally, it returns the minimum cost to reach the top, which is the minimum cost to reach the last step and the step before the last step.