// Helper function to evaluate longestsubarrayatmostkdistinct for problem constraints.
function longestSubarrayAtMostKDistinct(nums, k) {
    const count = new Map();
    let l = 0, maxLen = 0;

    for (let r = 0; r < nums.length; r++) {
        count.set(nums[r], (count.get(nums[r]) || 0) + 1);
        while (count.size > k) {
            const left = nums[l++];
            count.set(left, count.get(left) - 1);
            if (count.get(left) === 0) count.delete(left);
        }
        maxLen = Math.max(maxLen, r - l + 1);
    }
    return maxLen;
}

module.exports = { longestSubarrayAtMostKDistinct };