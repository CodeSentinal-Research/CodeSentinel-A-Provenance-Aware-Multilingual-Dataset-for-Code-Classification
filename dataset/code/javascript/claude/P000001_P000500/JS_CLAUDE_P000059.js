function productOfDigits(n) {
    n = Math.abs(n);
    if (n === 0) return 0;
    let prod = 1;
    while (n > 0) {
        prod *= (n % 10);
        n = Math.floor(n / 10);
    }
    return prod;
}

module.exports = { productOfDigits };
