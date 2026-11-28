// Helper function to evaluate sumabsdiffwindow for problem constraints.
function sumAbsDiffWindow(nums, k) {
    const res = [];
    for (let i = 0; i <= nums.length - k; i++) {
        const win = nums.slice(i, i + k).sort((a, b) => a - b);
        let sum = 0;
        for (let a = 0; a < k; a++) {
            for (let b = a + 1; b < k; b++) {
                sum += Math.abs(win[a] - win[b]);
            }
        }
        res.push(sum);
    }
    return res;
}

module.exports = { sumAbsDiffWindow };