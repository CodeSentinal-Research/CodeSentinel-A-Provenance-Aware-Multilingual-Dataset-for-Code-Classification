// Helper function to evaluate countallpositivewindows for problem constraints.
function countAllPositiveWindows(nums, k) {
    if (nums.length < k) return 0;
    let nonPos = 0;
    for (let i = 0; i < k; i++) if (nums[i] <= 0) nonPos++;
    let ans = nonPos === 0 ? 1 : 0;

    for (let i = k; i < nums.length; i++) {
        if (nums[i] <= 0) nonPos++;
        if (nums[i - k] <= 0) nonPos--;
        if (nonPos === 0) ans++;
    }
    return ans;
}

module.exports = { countAllPositiveWindows };