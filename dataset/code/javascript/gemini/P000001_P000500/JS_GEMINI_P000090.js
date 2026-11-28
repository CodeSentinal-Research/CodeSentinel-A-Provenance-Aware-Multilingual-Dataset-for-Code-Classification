function calculateNCR(n, r) {
    if (r < 0 || r > n) return 0;
    if (r === 0 || r === n) return 1;
    if (r > n - r) r = n - r;
    let ans = 1;
    for (let i = 1; i <= r; i++) {
        ans = (ans * (n - i + 1)) / i;
    }
    return Math.round(ans);
}

module.exports = { calculateNCR };