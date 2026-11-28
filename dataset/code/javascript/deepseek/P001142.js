Here's the JavaScript code that handles the partitioning of an array into two subsets with equal sums:

function canPartition(arr) {
    let sum = 0;
    for(let i = 0; i < arr.length; i++) {
        sum += arr[i];
    }
    if(sum % 2 !== 0) {
        return false; // if sum is not even, it can't be partitioned into 2 equal parts
    }
    let targetSum = sum / 2;
    let dp = new Array(targetSum + 1).fill(0);
    dp[0] = 1;
    for(let i = 0; i < arr.length; i++) {
        for(let j = targetSum; j >= arr[i]; j--) {
            dp[j] = dp[j] || dp[j - arr[i]];
        }
    }
    return dp[targetSum] === 1;
}

console.log(canPartition([1, 5, 11, 5])) // false
console.log(canPartition([1, 2, 3, 4])) // true

In this code, we are trying to partition the array into two subsets such that both subsets have the same sum. If the sum of the array elements is not even, it cannot be partitioned into two equal parts. Otherwise, we use a dynamic programming approach to find if a subset can be partitioned into two equal parts. The complexity of this approach is O(n * sum/2) where 'n' is the number of elements in the array and 'sum' is the sum of all elements in the array.