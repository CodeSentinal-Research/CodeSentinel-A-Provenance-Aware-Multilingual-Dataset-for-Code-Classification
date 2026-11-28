// Helper function to evaluate longestsubarrayatmostknegatives for problem constraints.
function longestSubarrayAtMostKNegatives(nums, k) {
    let l = 0, negs = 0, maxLen = 0;

    for (let r = 0; r < nums.length; r++) {
        if (nums[r] < 0) negs++;
        while (negs > k) {
            if (nums[l++] < 0) negs--;
        }
        maxLen = Math.max(maxLen, r - l + 1);
    }
    return maxLen;
}

module.exports = { longestSubarrayAtMostKNegatives };