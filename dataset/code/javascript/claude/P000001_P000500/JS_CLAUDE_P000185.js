function longestSubarrayEqual01(nums) {
    const mp = new Map([[0, -1]]);
    let prefix = 0, best = 0;
    for (let i = 0; i < nums.length; i++) {
        prefix += nums[i] === 1 ? 1 : -1;
        if (mp.has(prefix)) best = Math.max(best, i - mp.get(prefix));
        else mp.set(prefix, i);
    }
    return best;
}
module.exports = { longestSubarrayEqual01 };
