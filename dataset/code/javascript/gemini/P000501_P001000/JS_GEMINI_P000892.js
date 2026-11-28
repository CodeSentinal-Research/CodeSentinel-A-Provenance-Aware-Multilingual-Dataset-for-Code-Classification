// Checks prime status or generates prime numbers using sieve.
function primeFactors(n) {
    const factors = [];
    let d = 2;
    while (d * d <= n) {
        while (n % d === 0) {
            factors.push(d);
            n = Math.floor(n / d);
        }
        d++;
    }
    if (n > 1) factors.push(n);
    return factors;
}

module.exports = { primeFactors };