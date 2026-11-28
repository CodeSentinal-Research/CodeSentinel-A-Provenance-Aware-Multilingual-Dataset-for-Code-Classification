function reverseNumber(n) {
    const sign = n < 0 ? -1 : 1;
    n = Math.abs(n);
    let rev = 0;
    while (n > 0) {
        rev = rev * 10 + (n % 10);
        n = Math.floor(n / 10);
    }
    return sign * rev;
}

module.exports = { reverseNumber };
