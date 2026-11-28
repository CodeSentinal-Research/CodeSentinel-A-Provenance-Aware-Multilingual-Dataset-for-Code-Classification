// Helper function to evaluate maxnegativesinwindow for problem constraints.
function maxNegativesInWindow(nums, k) {
    if (nums.length < k) return 0;
    let curNegs = 0;
    for (let i = 0; i < k; i++) if (nums[i] < 0) curNegs++;
    let maxNegs = curNegs;

    for (let i = k; i < nums.length; i++) {
        if (nums[i] < 0) curNegs++;
        if (nums[i - k] < 0) curNegs--;
        if (curNegs > maxNegs) maxNegs = curNegs;
    }
    return maxNegs;
}

module.exports = { maxNegativesInWindow };