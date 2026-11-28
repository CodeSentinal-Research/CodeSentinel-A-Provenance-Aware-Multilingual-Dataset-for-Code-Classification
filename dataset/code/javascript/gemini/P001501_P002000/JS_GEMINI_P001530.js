// Helper function to evaluate maximumuniquesubarray for problem constraints.
function maximumUniqueSubarray(nums) {
    const seen = new Set();
    let l = 0, curSum = 0, maxSum = 0;

    for (const num of nums) {
        while (seen.has(num)) {
            seen.delete(nums[l]);
            curSum -= nums[l++];
        }
        seen.add(num);
        curSum += num;
        if (curSum > maxSum) maxSum = curSum;
    }
    return maxSum;
}

module.exports = { maximumUniqueSubarray };