// Helper function to evaluate countwindowscontainingzero for problem constraints.
function countWindowsContainingZero(nums, k) {
    if (nums.length < k) return 0;
    let zeros = 0;
    for (let i = 0; i < k; i++) if (nums[i] === 0) zeros++;
    let ans = zeros > 0 ? 1 : 0;

    for (let i = k; i < nums.length; i++) {
        if (nums[i] === 0) zeros++;
        if (nums[i - k] === 0) zeros--;
        if (zeros > 0) ans++;
    }
    return ans;
}

module.exports = { countWindowsContainingZero };