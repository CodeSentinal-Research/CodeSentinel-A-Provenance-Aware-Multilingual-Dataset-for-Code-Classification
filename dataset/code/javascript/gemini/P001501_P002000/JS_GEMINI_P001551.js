// Helper function to evaluate longestsubarraysumlek for problem constraints.
function longestSubarraySumLeK(nums, k) {
    let l = 0, curSum = 0, maxLen = 0;

    for (let r = 0; r < nums.length; r++) {
        curSum += nums[r];
        while (curSum > k && l <= r) {
            curSum -= nums[l++];
        }
        if (curSum <= k) {
            maxLen = Math.max(maxLen, r - l + 1);
        }
    }
    return maxLen;
}

module.exports = { longestSubarraySumLeK };