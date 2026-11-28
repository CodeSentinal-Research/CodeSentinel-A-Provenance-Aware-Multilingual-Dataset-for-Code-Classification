function nPr(n, r) {
    if (r < 0 || r > n) return 0;
    let res = 1;
    for (let i = 0; i < r; i++) {
        res *= (n - i);
    }
    return res;
}

module.exports = { nPr };
