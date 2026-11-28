// Helper function to evaluate longestnicesubarray for problem constraints.
function longestNiceSubarray(nums) {
    let usedBits = 0, l = 0, maxLen = 0;

    for (let r = 0; r < nums.length; r++) {
        while ((usedBits & nums[r]) !== 0) {
            usedBits ^= nums[l++];
        }
        usedBits |= nums[r];
        if (r - l + 1 > maxLen) maxLen = r - l + 1;
    }
    return maxLen;
}

module.exports = { longestNiceSubarray };