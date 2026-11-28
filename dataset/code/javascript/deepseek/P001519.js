Here is the JavaScript code for the problem:

let readline = require('readline');

const rl = readline.createInterface({
    input: process.stdin,
    output: process.stdout
});

let N = parseInt(rl.question().split(' ')[0]);
let arr = rl.question().split(' ').map(Number);

console.log(findLongestIncreasingSubsequence(arr, N));

rl.close();

function findLongestIncreasingSubsequence(arr, N){

    if (N == 1)
        return 1;

    let dp = new Array(N+1).fill(1);
    let maxLength = 1;

    for(let i = 1; i < N; i++){
        for(let j = 0; j < i; j++){
            if (arr[i] > arr[j]) {
                dp[i] = Math.max(dp[i], dp[j] + 1);
            }
       
            maxLength = Math.max(maxLength, dp[i]);
        }
    }

    return maxLength;
}

In this code, we are using dynamic programming. The `dp` array is used to store the maximum length ending at index `i`. For each index `i`, we check all the previous indices `j` where `arr[i] > arr[j]`, and update `dp[i]` by `dp[j] + 1` (we add 1 to include the current number). Finally, the maximum length is stored in `maxLength`. The `maxLength` is the longest increasing subsequence ending at index `i`.