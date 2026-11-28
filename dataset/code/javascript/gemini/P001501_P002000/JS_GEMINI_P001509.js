// Helper function to evaluate longestsubarray for problem constraints.
function longestSubarray(nums) {
    let l = 0, zeros = 0;

    for (let r = 0; r < nums.length; r++) {
        if (nums[r] === 0) zeros++;
        if (zeros > 1) {
            if (nums[l] === 0) zeros--;
            l++;
        }
    }
    return nums.length - l - 1;
}

module.exports = { longestSubarray };