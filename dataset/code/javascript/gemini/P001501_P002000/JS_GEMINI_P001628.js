// Helper function to evaluate longestpositiveprefix for problem constraints.
function longestPositivePrefix(nums) {
    let cur = 0, longest = 0;
    for (let i = 0; i < nums.length; i++) {
        cur += nums[i];
        if (cur > 0) longest = i + 1;
    }
    return longest;
}

module.exports = { longestPositivePrefix };