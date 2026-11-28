function largestDivisibleSubset(nums) {
    nums.sort((a, b) => a - b);
    let dp = new Array(nums.length).fill(1);
    let max = 1;
    let maxIndex = 0;
    
    for (let i = 1; i < nums.length; i++) {
        for (let j = 0; j < i; j++) {
            if (nums[i] % nums[j] === 0) {
                dp[i] = Math.max(dp[i], dp[j] + 1);
            }
        }
        max = Math.max(max, dp[i]);
    }
    
    for (let i = 0; i < nums.length; i++) {
        if (dp[i] === max) {
            console.log(nums[i]);
            break;
        }
    }
    
    return max;
}