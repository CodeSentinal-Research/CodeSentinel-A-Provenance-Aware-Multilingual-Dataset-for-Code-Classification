function longestSubarrayWithSumK(nums, k) {
    const map = new Map([[0, -1]]);
    let prefix = 0, best = 0;
    for (let i = 0; i < nums.length; i++) {
        prefix += nums[i];
        if (map.has(prefix - k)) best = Math.max(best, i - map.get(prefix - k));
        if (!map.has(prefix)) map.set(prefix, i);
    }
    return best;
}
module.exports = { longestSubarrayWithSumK };
