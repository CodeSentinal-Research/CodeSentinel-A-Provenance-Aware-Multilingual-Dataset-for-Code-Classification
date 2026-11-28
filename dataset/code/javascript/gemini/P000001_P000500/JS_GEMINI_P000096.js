function isSpyNumber(n) {
    n = Math.abs(n);
    let sum = 0;
    let prod = 1;
    while (n > 0) {
        let d = n % 10;
        sum += d;
        prod *= d;
        n = Math.floor(n / 10);
    }
    return sum === prod;
}

module.exports = { isSpyNumber };