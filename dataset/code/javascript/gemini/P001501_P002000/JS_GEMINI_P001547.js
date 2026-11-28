// Helper function to evaluate maxoddsinwindow for problem constraints.
function maxOddsInWindow(nums, k) {
    if (nums.length < k) return 0;
    let curOdds = 0;
    for (let i = 0; i < k; i++) if (nums[i] % 2 !== 0) curOdds++;
    let maxOdds = curOdds;

    for (let i = k; i < nums.length; i++) {
        if (nums[i] % 2 !== 0) curOdds++;
        if (nums[i - k] % 2 !== 0) curOdds--;
        if (curOdds > maxOdds) maxOdds = curOdds;
    }
    return maxOdds;
}

module.exports = { maxOddsInWindow };