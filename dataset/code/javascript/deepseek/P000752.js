Here is a JavaScript function that finds the first subsequence with the given sum in an array.

function findFirstSubsequence(nums, target) {
    let n = nums.length;
    let dp = new Array(target + 1).fill(null);
    dp[0] = [];

    for (let i = 1; i <= target; i++) {
        if (dp[i] !== null) {
            for (let num of nums) {
                if (i + num <= target) {
                    dp[i + num] = dp[i].concat([num]);
                }
            }
        }
    }

    if (dp[target] !== null) {
        return dp[target];
    } else {
        return -1;
    }
}

This function uses dynamic programming to find all subsequences with the given sum. The base case is when target is 0, in which case no subsequence is possible. Then for each number in the input array, we check if adding it to the current target can form a larger target. If it can, then we update our dynamic programming table. After iterating through all the numbers, we check if there is a subsequence with the target sum. If there is, we return the subsequence, otherwise we return -1.