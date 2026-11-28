function sumOddNumbers(n) {
    if (n < 1) return 0;
    const k = Math.floor((n + 1) / 2);
    return k * k;
}

module.exports = { sumOddNumbers };
