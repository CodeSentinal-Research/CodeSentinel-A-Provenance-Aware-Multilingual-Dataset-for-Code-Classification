// Helper function to evaluate longestbinarysubarraykzeros for problem constraints.
function longestBinarySubarrayKZeros(nums, k) {
    let l = 0, zeros = 0, maxLen = 0;

    for (let r = 0; r < nums.length; r++) {
        if (nums[r] === 0) zeros++;
        while (zeros > k) {
            if (nums[l++] === 0) zeros--;
        }
        maxLen = Math.max(maxLen, r - l + 1);
    }
    return maxLen;
}

module.exports = { longestBinarySubarrayKZeros };