function sumOfGP(a, r, n) {
    if (n <= 0) return 0;
    if (r === 1) return a * n;
    return a * (1 - Math.pow(r, n)) / (1 - r);
}

module.exports = { sumOfGP };