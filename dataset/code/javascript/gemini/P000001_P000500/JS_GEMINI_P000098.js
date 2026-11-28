// Checks prime status or generates prime numbers using sieve.
function sumOfPrimes(n) {
    if (n < 2) return 0;
    const isPrime = new Uint8Array(n + 1).fill(1);
    isPrime[0] = isPrime[1] = 0;
    for (let p = 2; p * p <= n; p++) {
        if (isPrime[p]) {
            for (let i = p * p; i <= n; i += p) {
                isPrime[i] = 0;
            }
        }
    }
    let sum = 0;
    for (let i = 2; i <= n; i++) {
        if (isPrime[i]) sum += i;
    }
    return sum;
}

module.exports = { sumOfPrimes };