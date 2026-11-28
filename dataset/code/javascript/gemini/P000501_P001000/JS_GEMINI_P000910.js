// Helper function to evaluate npr for problem constraints.
function nPr(n, r) {
    if (r < 0 || r > n) return 0;
    let ans = 1;
    for (let i = 0; i < r; i++) {
        ans *= (n - i);
    }
    return ans;
}

module.exports = { nPr };