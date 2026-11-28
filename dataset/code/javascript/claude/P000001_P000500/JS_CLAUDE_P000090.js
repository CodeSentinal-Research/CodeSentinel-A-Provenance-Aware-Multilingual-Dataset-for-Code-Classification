function nCr(n, r) {
    if (r < 0 || r > n) return 0;
    if (r === 0 || r === n) return 1;
    if (r > n / 2) r = n - r;
    let res = 1;
    for (let i = 1; i <= r; i++) {
        res = (res * (n - i + 1)) / i;
    }
    return Math.round(res);
}

module.exports = { nCr };
