function subsetSum(arr, sum) {
    let dp = new Array(sum + 1).fill(false);
    dp[0] = true;
    
    for (let i = 0; i < arr.length; i++) {
        for (let j = sum; j >= arr[i]; j--) {
            dp[j] = dp[j] || dp[j - arr[i]];
        }
    }
    
    return dp[sum];
}

let [N, S] = readline().split(" ").map(Number);
let arr = readline().split(" ").map(Number);

console.log(subsetSum(arr, S) ? 'YES' : 'NO');

In this code, we use a dynamic programming approach to solve the Subset Sum Problem. The dp array is initialized with all elements set to false, and the initial condition is that the sum of subset with sum 0 is true. Then for each number in the array, we iterate from the sum to the number and update the dp array accordingly. If the current number can be included in the sum, we set the value of dp[j] to true or if dp[j - arr[i]] is true, which means the sum of previous numbers can also be found.