function maxSubarraySumCircular(nums) {
    let total = 0;
    let maxSum = nums[0], curMax = 0;
    let minSum = nums[0], curMin = 0;

    for (const x of nums) {
        curMax = Math.max(x, curMax + x);
        maxSum = Math.max(maxSum, curMax);

        curMin = Math.min(x, curMin + x);
        minSum = Math.min(minSum, curMin);

        total += x;
    }

    return maxSum < 0 ? maxSum : Math.max(maxSum, total - minSum);
}

module.exports = { maxSubarraySumCircular };