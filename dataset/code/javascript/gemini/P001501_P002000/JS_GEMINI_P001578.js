// Helper function to evaluate countdistinctwindows for problem constraints.
function countDistinctWindows(nums, k) {
    if (nums.length < k) return 0;
    const count = new Map();
    for (let i = 0; i < k; i++) count.set(nums[i], (count.get(nums[i]) || 0) + 1);
    let ans = count.size === k ? 1 : 0;

    for (let i = k; i < nums.length; i++) {
        count.set(nums[i], (count.get(nums[i]) || 0) + 1);
        count.set(nums[i - k], count.get(nums[i - k]) - 1);
        if (count.get(nums[i - k]) === 0) count.delete(nums[i - k]);
        if (count.size === k) ans++;
    }
    return ans;
}

module.exports = { countDistinctWindows };