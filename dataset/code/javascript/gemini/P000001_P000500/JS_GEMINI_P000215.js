function findMaxAverage(nums, k) {
    let curSum = 0;
    for (let i = 0; i < k; i++) curSum += nums[i];
    let maxSum = curSum;

    for (let i = k; i < nums.length; i++) {
        curSum += nums[i] - nums[i - k];
        if (curSum > maxSum) maxSum = curSum;
    }
    return maxSum / k;
}

module.exports = { findMaxAverage };