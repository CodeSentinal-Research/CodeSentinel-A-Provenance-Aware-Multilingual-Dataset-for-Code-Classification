// Helper function to evaluate minsubarraylen for problem constraints.
function minSubArrayLen(target, nums) {
    let l = 0, curSum = 0, ans = Infinity;

    for (let r = 0; r < nums.length; r++) {
        curSum += nums[r];
        while (curSum >= target) {
            ans = Math.min(ans, r - l + 1);
            curSum -= nums[l++];
        }
    }
    return ans !== Infinity ? ans : 0;
}

module.exports = { minSubArrayLen };