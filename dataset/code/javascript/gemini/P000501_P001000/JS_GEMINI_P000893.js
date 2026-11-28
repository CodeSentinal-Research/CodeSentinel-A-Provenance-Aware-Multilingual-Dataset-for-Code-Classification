// Checks prime status or generates prime numbers using sieve.
function distinctPrimeFactors(n) {
    const factors = [];
    let d = 2;
    while (d * d <= n) {
        if (n % d === 0) {
            factors.push(d);
            while (n % d === 0) n = Math.floor(n / d);
        }
        d++;
    }
    if (n > 1) factors.push(n);
    return factors;
}

module.exports = { distinctPrimeFactors };