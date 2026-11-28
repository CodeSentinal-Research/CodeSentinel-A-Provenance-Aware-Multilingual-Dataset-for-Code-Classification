Here is the JavaScript code for the given problem:

function coinChange(amount, coins) {
    const dp = Array(amount + 1).fill(Infinity);
    dp[0] = 0;
    for(let i = 0; i < coins.length; i++) {
        for(let j = coins[i]; j <= amount; j++) {
            dp[j] = Math.min(dp[j], dp[j - coins[i]] + 1);
        }
    }
    if(dp[amount] === Infinity) {
        return -1;
    } else {
        return dp[amount];
    }
}

In this code, `dp` array is used to store the minimum number of coins required for each amount up to `amount`. We start by initializing the `dp` array with Infinity for amounts less than or equal to 0. Then, for each coin, we update `dp` array for each amount up to the coin denomination. If `dp[j]` is still Infinity (i.e., we have not found the minimum number of coins for this amount), we set it to be the minimum of `dp[j]` and `dp[j - coin] + 1`. In the end, if `dp[amount]` is still Infinity, it means we have not found the minimum number of coins for this amount, so we return -1. Otherwise, we return the minimum number of coins.