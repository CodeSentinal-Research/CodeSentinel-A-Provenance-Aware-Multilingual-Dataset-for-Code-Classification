// Helper function to evaluate longestsubarrayatmostkodds for problem constraints.
function longestSubarrayAtMostKOdds(nums, k) {
    let l = 0, odds = 0, maxLen = 0;

    for (let r = 0; r < nums.length; r++) {
        if (nums[r] % 2 !== 0) odds++;
        while (odds > k) {
            if (nums[l++] % 2 !== 0) odds--;
        }
        maxLen = Math.max(maxLen, r - l + 1);
    }
    return maxLen;
}

module.exports = { longestSubarrayAtMostKOdds };