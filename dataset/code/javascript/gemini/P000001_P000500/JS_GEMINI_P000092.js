function sumOfAP(a, d, n) {
    if (n <= 0) return 0;
    return (n / 2.0) * (2.0 * a + (n - 1) * d);
}

module.exports = { sumOfAP };