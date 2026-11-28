Here is the JavaScript code for your problem:

function findWays(N, K) {
  let dp = new Array(N).fill(0);
  dp[0] = K;
  dp[1] = K;

  for(let i = 2; i < N; i++){
    dp[i] = (dp[i-1] + dp[i-2]) * (K-1);
  }

  let result = dp[N-1];
  return result;
}

function main() {
  const input = require('fs').readFileSync('/dev/stdin', 'utf8');
  const [N, K] = input.split(' ').map(Number);
  console.log(findWays(N, K));
}

main();

This code uses dynamic programming to solve the problem. The `dp` array stores the number of ways to paint the fence if the last fence post is of a different color than the previous one. The base cases of `dp` are set to `K`, as there can only be `K` different colors. For each remaining fence post, we calculate the number of ways to paint it, which is `(K - 1)` times the sum of the ways to paint the two adjacent fence posts. The result is the last element of `dp`.