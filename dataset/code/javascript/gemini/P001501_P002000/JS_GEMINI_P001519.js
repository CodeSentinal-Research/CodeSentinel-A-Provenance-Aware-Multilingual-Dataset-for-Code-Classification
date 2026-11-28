// Helper function to evaluate findlengthoflcis for problem constraints.
function findLengthOfLCIS(nums) {
    if (nums.length === 0) return 0;
    let ans = 1, cur = 1;
    for (let i = 1; i < nums.length; i++) {
        if (nums[i] > nums[i - 1]) {
            cur++;
            if (cur > ans) ans = cur;
        } else {
            cur = 1;
        }
    }
    return ans;
}

module.exports = { findLengthOfLCIS };