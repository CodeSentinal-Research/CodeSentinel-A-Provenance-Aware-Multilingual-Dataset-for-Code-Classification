function eggDrop(eggs, floors) {
    // Base cases
    if(eggs == 1) {
        return floors;
    }
    if(floors == 0 || floors == 1) {
        return floors;
    }

    // DP table to store subproblems
    let dp = new Array(eggs + 1);
    for(let i = 0; i <= eggs; i++) {
        dp[i] = new Array(floors + 1).fill(0);
    }

    // Fill up the dp table
    for(let i = 1; i <= eggs; i++) {
        dp[i][1] = 1;
        dp[i][0] = 0;
    }

    for(let j = 1; j <= floors; j++) {
        dp[1][j] = j;
    }

    // Fill up the dp table with bottom-up approach
    for(let i = 2; i <= eggs; i++) {
        for(let j = 2; j <= floors; j++) {
            dp[i][j] = dp[i][j-1] + dp[i-1][j-1] + 1;
            for(let k = 1; k < j; k++) {
                dp[i][j] = Math.min(dp[i][j], Math.max(dp[i-1][k-1], dp[i][j-k-1]) + 1);
            }
        }
    }

    return dp[eggs][floors];
}

// Testing the function
console.log(eggDrop(2, 500));

This JavaScript code provides a recursive solution to the Egg Dropping problem. It first checks for the base cases of when there is only one egg and only one floor. Then, it creates a dynamic programming (DP) table to store the subproblems of the problem. The DP table is filled up bottom-up, first for the smallest number of attempts (1), and then for all other attempts.

Finally, the minimum number of attempts (dp[eggs][floors]) is returned from the function.