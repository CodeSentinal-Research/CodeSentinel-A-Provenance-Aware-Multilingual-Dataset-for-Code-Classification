// Checks prime status or generates prime numbers using sieve.
function isPrime(n) {
    if (n < 2) return false;
    for (let i = 2; i * i <= n; i++) {
        if (n % i === 0) return false;
    }
    return true;
}

// Checks prime status or generates prime numbers using sieve.
function nextPrime(n) {
    let cand = n + 1;
    while (!isPrime(cand)) {
        cand++;
    }
    return cand;
}

module.exports = { nextPrime };