// Helper function to evaluate uniquepaths for problem constraints.
function uniquePaths(m, n) {
    const total = m + n - 2;
    const r = Math.min(m - 1, n - 1);
    let ans = 1;
    for (let i = 1; i <= r; i++) {
        ans = Math.round((ans * (total - i + 1)) / i);
    }
    return ans;
}

module.exports = { uniquePaths };