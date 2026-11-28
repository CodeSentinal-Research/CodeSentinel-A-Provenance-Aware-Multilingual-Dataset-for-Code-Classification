Here is a JavaScript solution using Dynamic Programming:

function distributeBalls(N, K) {
    if (N < 0 || K < 0 || N > K || K > 10000 || N > 10000) {
        throw new Error('Invalid Inputs');
    }

    let dp = new Array(K + 1).fill(0).map(() => new Array(N + 1).fill(0));

    for(let i = 0; i <= K; i++) {
        dp[i][0] = 1;
    }

    for(let i = 1; i <= K; i++) {
        for(let j = 1; j <= N; j++) {
            dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
        }
    }

    return dp[K][N];
}

In this code, we first create a dynamic programming (dp) array, where dp[i][j] represents the number of ways to distribute N identical balls into K boxes such that each box may contain zero or more balls. 

We then initialize our base cases. For the dp array, if we have only one box, we can distribute N identical balls into one box.

Finally, we iterate over all other cases and calculate the dp array by summing the cases of previous boxes and previous balls.

The time complexity is O(K*N) and the space complexity is also O(K*N).