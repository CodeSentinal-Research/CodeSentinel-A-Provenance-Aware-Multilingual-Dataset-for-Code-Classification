// Helper function to evaluate countalternatingsubarrays for problem constraints.
function countAlternatingSubarrays(nums) {
    let ans = 1, curLen = 1;

    for (let i = 1; i < nums.length; i++) {
        if (nums[i] !== nums[i - 1]) {
            curLen++;
        } else {
            curLen = 1;
        }
        ans += curLen;
    }
    return ans;
}

module.exports = { countAlternatingSubarrays };