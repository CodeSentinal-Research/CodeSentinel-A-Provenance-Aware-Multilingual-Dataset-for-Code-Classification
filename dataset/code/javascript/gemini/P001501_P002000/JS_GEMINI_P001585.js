// Helper function to evaluate maxfrequency for problem constraints.
function maxFrequency(nums, k) {
    nums.sort((a, b) => a - b);
    let l = 0, ans = 1;
    let total = 0;

    for (let r = 0; r < nums.length; r++) {
        total += nums[r];
        while (nums[r] * (r - l + 1) - total > k) {
            total -= nums[l++];
        }
        if (r - l + 1 > ans) ans = r - l + 1;
    }
    return ans;
}

module.exports = { maxFrequency };