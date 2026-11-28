Here's the JavaScript code for the problem:

function largestDivisibleSubset(nums) {
    nums.sort((a, b) => a - b);
    let dp = new Array(nums.length).fill(1);
    let parent = new Array(nums.length).fill(null);

    let maxIndex = 0;
    for(let i = 1; i < nums.length; i++) {
        for(let j = 0; j < i; j++) {
            if(nums[i] % nums[j] === 0 && dp[i] < dp[j] + 1) {
                dp[i] = dp[j] + 1;
                parent[i] = j;
            }
        }

        if(dp[i] > dp[maxIndex]) {
            maxIndex = i;
        }
    }

    let subset = [];
    while(maxIndex !== null) {
        subset.push(nums[maxIndex]);
        maxIndex = parent[maxIndex];
    }

    return subset.reverse();
}

This code first sorts the array in ascending order. It then initializes a dynamic programming array `dp` to keep track of the longest divisible subset ending at each index. The `parent` array keeps track of the index in the previous array.

It then iterates through the array, checking for every pair (a, b) if a divides b or b divides a. If it does, it updates the `dp` array and the `parent` array. The maximum `dp` value is updated if a larger value is found.

Finally, it constructs the largest divisible subset by backtracking from the maximum `dp` value to the first index.