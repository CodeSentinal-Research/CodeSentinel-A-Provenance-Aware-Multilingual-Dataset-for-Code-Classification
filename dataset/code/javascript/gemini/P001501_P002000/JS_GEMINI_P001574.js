// Helper function to evaluate maxfirstwindow for problem constraints.
function maxFirstWindow(nums, k) {
    return Math.max(...nums.slice(0, k));
}

module.exports = { maxFirstWindow };