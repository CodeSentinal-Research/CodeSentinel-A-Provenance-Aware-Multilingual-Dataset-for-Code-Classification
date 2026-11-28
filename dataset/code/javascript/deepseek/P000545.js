Here is a JavaScript solution for the problem:

function constrainedSubsetSum(nums, k) {
    const dp = new Array(nums.length).fill(0);
    const dpPre = new Array(nums.length).fill(0);
    let maxSum = nums[0];

    dp[0] = nums[0];
    dpPre[0] = nums[0];

    for(let i = 1; i < nums.length; i++){
        dp[i] = Math.max(nums[i], dp[i - 1] + nums[i]);
        dpPre[i] = Math.max(dpPre[i - 1], dp[i]);
        maxSum = Math.max(maxSum, dpPre[i]);
        if(i - k > 0){
            dp[i] = Math.max(dp[i], dpPre[i - k - 1] + nums[i]);
            dpPre[i] = Math.max(dpPre[i - 1], dp[i]);
        }
        if(dpPre[i] > maxSum){
            maxSum = dpPre[i];
        }
    }
    return maxSum;
}

This function uses a dynamic programming approach to solve the problem. The dp array stores the maximum sum of a non-empty subsequence for each element, and the dpPre array stores the maximum sum of a subsequence with each element. The maxSum variable stores the maximum sum of all subsequences.

The function iterates over the input array nums, updating the dp and dpPre arrays based on the current element. It also updates the maxSum and the maximum sum of all subsequences. If the current element is greater than k from the previous element, the function also updates the dp and dpPre arrays for the subsequence with the current element.

Finally, the function returns the maxSum, which is the maximum sum of a non-empty subsequence with all elements being non-negative, and their indices differ by at most k.