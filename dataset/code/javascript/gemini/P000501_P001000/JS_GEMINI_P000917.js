// Helper function to evaluate starsandbars for problem constraints.
function starsAndBars(n, k) {
    const total = n + k - 1;
    let r = k - 1;
    if (r < 0 || r > total) return 0;
    if (r > total - r) r = total - r;
    let ans = 1;
    for (let i = 1; i <= r; i++) {
        ans = Math.round((ans * (total - i + 1)) / i);
    }
    return ans;
}

module.exports = { starsAndBars };