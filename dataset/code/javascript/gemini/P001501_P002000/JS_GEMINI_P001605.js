// Helper function to evaluate maxsubarraylensumk for problem constraints.
function maxSubarrayLenSumK(nums, k) {
    const seen = new Map();
    seen.set(0, -1);
    let curSum = 0, maxLen = 0;

    for (let i = 0; i < nums.length; i++) {
        curSum += nums[i];
        if (seen.has(curSum - k)) {
            maxLen = Math.max(maxLen, i - seen.get(curSum - k));
        }
        if (!seen.has(curSum)) seen.set(curSum, i);
    }
    return maxLen;
}

module.exports = { maxSubarrayLenSumK };