function classify(n) {
    if (n > 0) return 'Positive';
    if (n < 0) return 'Negative';
    return 'Zero';
}

module.exports = { classify };
