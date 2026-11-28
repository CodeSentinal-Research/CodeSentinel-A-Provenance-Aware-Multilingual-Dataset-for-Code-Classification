// Checks prime status or generates prime numbers using sieve.
function countCoprime(n, r) {
    const primes = [];
    let temp = n;
    let d = 2;
    while (d * d <= temp) {
        if (temp % d === 0) {
            primes.push(d);
            while (temp % d === 0) temp = Math.floor(temp / d);
        }
        d++;
    }
    if (temp > 1) primes.push(temp);

    const m = primes.length;
    let divCount = 0;
    for (let mask = 1; mask < (1 << m); mask++) {
        let prod = 1, bits = 0;
        for (let i = 0; i < m; i++) {
            // If current bit is set, multiply base into result
            if ((mask >> i) & 1) {
                prod *= primes[i];
                bits++;
            }
        }
        if (bits % 2 === 1) divCount += Math.floor(r / prod);
        else divCount -= Math.floor(r / prod);
    }
    return r - divCount;
}

module.exports = { countCoprime };