// Helper function to evaluate ncr for problem constraints.
function nCr(n, r) {
    if (r < 0 || r > n) return 0;
    if (r === 0 || r === n) return 1;
    if (r > n - r) r = n - r;
    let ans = 1;
    for (let i = 1; i <= r; i++) {
        ans = (ans * (n - i + 1)) / i;
    }
    return ans;
}

// Helper function to evaluate probheads for problem constraints.
function probHeads(n, k, p) {
    return nCr(n, k) * Math.pow(p, k) * Math.pow(1 - p, n - k);
}

module.exports = { probHeads };