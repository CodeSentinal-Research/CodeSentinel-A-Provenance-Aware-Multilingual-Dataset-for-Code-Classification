// Helper function to evaluate longestones for problem constraints.
function longestOnes(nums, k) {
    let l = 0;
    for (let r = 0; r < nums.length; r++) {
        if (nums[r] === 0) k--;
        if (k < 0) {
            if (nums[l] === 0) k++;
            l++;
        }
    }
    return nums.length - l;
}

module.exports = { longestOnes };