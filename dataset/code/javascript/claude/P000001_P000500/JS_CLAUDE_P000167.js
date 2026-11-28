function longestIncreasingSubarray(nums) {
    if (!nums.length) return 0;
    let best = 1, cur = 1;
    for (let i = 1; i < nums.length; i++) {
        cur = nums[i] > nums[i-1] ? cur+1 : 1;
        best = Math.max(best, cur);
    }
    return best;
}
module.exports = { longestIncreasingSubarray };
