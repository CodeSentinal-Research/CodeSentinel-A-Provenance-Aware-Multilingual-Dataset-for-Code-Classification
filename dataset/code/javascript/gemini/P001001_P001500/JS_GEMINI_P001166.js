// Helper function to evaluate maxsubarraysumcircular for problem constraints.
function maxSubarraySumCircular(nums) {
    let totalSum = 0;
    let currMax = 0, maxSum = nums[0];
    let currMin = 0, minSum = nums[0];

    for (const x of nums) {
        currMax = Math.max(x, currMax + x);
        maxSum = Math.max(maxSum, currMax);
        currMin = Math.min(x, currMin + x);
        minSum = Math.min(minSum, currMin);
        totalSum += x;
    }

    return maxSum > 0 ? Math.max(maxSum, totalSum - minSum) : maxSum;
}

module.exports = { maxSubarraySumCircular };