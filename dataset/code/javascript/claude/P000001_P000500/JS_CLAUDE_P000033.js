function sumEvenNumbers(n) {
    if (n < 2) return 0;
    const k = Math.floor(n / 2);
    return k * (k + 1);
}

module.exports = { sumEvenNumbers };
