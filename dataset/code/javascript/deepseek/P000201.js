let readline = require('readline');

const rl = readline.createInterface({
    input: process.stdin,
    output: process.stdout
});

let N = parseInt(rl.question());
let arr = rl.question().split(' ').map(Number);

function maxSumIncreasingSubsequence(arr) {
    let dp = Array(N).fill(0);
    dp[0] = arr[0];

    for (let i = 1; i < N; i++) {
        dp[i] = arr[i];
        for (let j = 0; j < i; j++) {
            if (arr[i] > arr[j]) {
                dp[i] = Math.max(dp[i], dp[j] + arr[i]);
            }
        }
    }

    return Math.max(...dp);
}

console.log(maxSumIncreasingSubsequence(arr));

This JavaScript program reads the number of integers `N` and an array of integers from the standard input. It then creates a dynamic programming array `dp` of size `N`, and initializes the first element as the first element of the input array. It then iterates over the input array, updating the maximum sum for each index in `dp`.

The inner loop iterates over all previous indices in `dp`, and if the current element `arr[i]` is greater than the previous element `arr[j]`, it updates the maximum sum for index `i` as the maximum of `dp[i]` and the sum of `dp[j]` and `arr[i]`.

Finally, it returns the maximum sum of the increasing subsequence found in `dp`.