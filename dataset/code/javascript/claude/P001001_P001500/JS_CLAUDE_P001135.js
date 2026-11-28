function maxSubArray(nums) {
    let maxSum = -Infinity, curr = 0;
    for (const x of nums) {
        curr += x;
        maxSum = Math.max(maxSum, curr);
        if (curr < 0) curr = 0;
    }
    return maxSum;
}

module.exports = { maxSubArray };
