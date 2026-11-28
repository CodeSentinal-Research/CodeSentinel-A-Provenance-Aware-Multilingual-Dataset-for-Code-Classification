// Helper function to evaluate countincreasingwindows for problem constraints.
function countIncreasingWindows(nums, k) {
    if (nums.length < k) return 0;
    let nonInc = 0;
    for (let i = 0; i < k - 1; i++) if (nums[i] >= nums[i + 1]) nonInc++;
    let ans = nonInc === 0 ? 1 : 0;

    for (let i = k; i < nums.length; i++) {
        if (nums[i - 1] >= nums[i]) nonInc++;
        if (nums[i - k] >= nums[i - k + 1]) nonInc--;
        if (nonInc === 0) ans++;
    }
    return ans;
}

module.exports = { countIncreasingWindows };