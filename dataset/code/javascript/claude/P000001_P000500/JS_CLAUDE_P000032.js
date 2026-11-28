function getFactors(n) {
    if (n <= 0) return [];
    const factors = [];
    for (let i = 1; i * i <= n; i++) {
        if (n % i === 0) {
            factors.push(i);
            if (i * i !== n) factors.push(n / i);
        }
    }
    return factors.sort((a, b) => a - b);
}

module.exports = { getFactors };
