function sumEvenSeries(n) {
    const k = Math.floor(n / 2);
    return k * (k + 1);
}

module.exports = { sumEvenSeries };
