// Helper function to evaluate smallestsubarraysumgtx for problem constraints.
function smallestSubarraySumGtX(nums, x) {
    let l = 0, curSum = 0, minLen = Infinity;

    for (let r = 0; r < nums.length; r++) {
        curSum += nums[r];
        while (curSum > x) {
            minLen = Math.min(minLen, r - l + 1);
            curSum -= nums[l++];
        }
    }
    return minLen !== Infinity ? minLen : 0;
}

module.exports = { smallestSubarraySumGtX };