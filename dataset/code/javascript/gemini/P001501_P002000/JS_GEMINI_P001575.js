// Helper function to evaluate minfirstwindow for problem constraints.
function minFirstWindow(nums, k) {
    return Math.min(...nums.slice(0, k));
}

module.exports = { minFirstWindow };